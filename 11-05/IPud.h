// Nombre de los alumnos
// Felix Garcia Ceballos, Raul Diego Navarro
// Usuario del Juez C36

#include "HashMap.h"
#include "List.h"
#include "Exceptions.h"

class IPud {

private:
	struct songInfo {
		string artist;
		int time;
		List<string>::Iterator playlistIt;
		List<string>::Iterator recentlistIt;
	};

	HashMap<string, songInfo> _songs;
	List<string> _playlist;
	List<string> _recentlist;

	int _playlistTotalTime = 0;

public:

	void addSong(string S, string A, int D) {
		if (_songs.contains(S)) throw InvalidAccessException("addSong");

		songInfo newInfo;

		newInfo.artist = A;
		newInfo.time = D;
		//Los iteradores apuntan fuera del recorrido, porque la cancion no esta en ninguna lista.
		newInfo.playlistIt = _playlist.end();
		newInfo.recentlistIt = _recentlist.end();

		_songs.insert(S, newInfo);
	};

	void addToPlaylist(string S){
		if (!_songs.contains(S)) throw InvalidAccessException("addToPlaylist");
		if (_songs[S].playlistIt == _playlist.end()) { //if no esta en la playlist.
			_playlistTotalTime += _songs[S].time;
			_playlist.push_front(S); //se anyaden por el principio.
			_songs[S].playlistIt = _playlist.begin(); //el iterador apunta a la cancion.
		} //else no hace nada.
	};

	string current(){
		if (_playlist.empty()) throw InvalidAccessException("current");
		else return _playlist.back();
	};

	string play(){
		if (!_playlist.empty()) {
			string playSong = _playlist.back();
			_playlist.pop_back();
			_playlistTotalTime -= _songs[playSong].time;
			_songs[playSong].playlistIt = _playlist.end();
			//si ya habia sido escuchada recientemente se borra de la lista
			if (_songs[playSong].recentlistIt != _recentlist.end()) { _recentlist.erase(_songs[playSong].recentlistIt); }
			_recentlist.push_front(playSong); //se mete al principio
			_songs[playSong].recentlistIt = _recentlist.begin(); //se pone el iterador

			return playSong;
		}
		else return "";
	};

	int totalTime(){ return _playlistTotalTime; };

	List<string> recent(int N){
		int i = 0;
		List<string> output;
		List<string>::ConstIterator it = _recentlist.cbegin();
		while (i < N && it != _recentlist.cend()) {
			output.push_back(it.elem());
			it.next();
			i++;
		}
	
		return output;
	};

	void deleteSong(string S){
		if (_songs.contains(S)) { //si esta en el IPud
			if (_songs[S].playlistIt != _playlist.end()) { //si esta en playlist
				_playlist.erase(_songs[S].playlistIt);
				_playlistTotalTime -= _songs[S].time;
			}
			if (_songs[S].recentlistIt != _recentlist.end()) { //si esta en recentlist
				_recentlist.erase(_songs[S].recentlistIt);
			}
			_songs.erase(S);
		} //si no no hace nada
	};
};