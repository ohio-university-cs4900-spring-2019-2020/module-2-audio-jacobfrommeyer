#include "audio_mgr.h"
#include <iostream>

using namespace Aftr;
using namespace std;

audio_mgr* audio_mgr::init()
{
	audio_mgr* engine = new audio_mgr();
	irrklang::ISoundEngine* temp = irrklang::createIrrKlangDevice();

	if (!engine)
	{
		cout << "Failed to start irrKlang engine" << endl;
	}
	else
	{
		cout << "Started irrKlang engine" << endl;
	}

	engine->set_audio_engine(temp);

	return engine;
}

void audio_mgr::set_audio_engine(irrklang::ISoundEngine* audio_engine)
{
	this->engine = audio_engine;
}

void audio_mgr::play_2D_audio(const char* audio_file, bool loop, bool pause, bool track)
{
	if (!this->engine)
	{
		return;
	}

	this->sound2D.push_back(this->engine->play2D(audio_file, loop, pause, track));
}

void audio_mgr::play_3D_audio(const char* audio_file, Aftr::Vector location, bool loop, bool pause, bool track)
{
	if (!this->engine)
	{
		return;
	}

	this->sound3D.push_back(this->engine->play3D(audio_file, this->vector_con(location), loop, pause, track));
}

irrklang::vec3df audio_mgr::vector_con(Vector location)
{
	return irrklang::vec3df(location.x, location.y, location.z);
}

irrklang::ISoundEngine* audio_mgr::get_audio_engine()
{
	return this->engine;
}

std::vector<irrklang::ISound*> audio_mgr::get_2D_audio()
{
	return this->sound2D;
}

std::vector<irrklang::ISound*> audio_mgr::get_3D_audio()
{
	return this->sound3D;
}

void audio_mgr::stop_2d_audio()
{
	if (sound2D.empty())
	{
		return;
	}

	cout << "2D sound stopped." << endl;

	sound2D.at(0)->stop();
	sound2D.erase(sound2D.begin());
}

void audio_mgr::stop_3d_audio()
{
	if (sound3D.empty())
	{
		return;
	}

	cout << "3D sound stopped." << endl;

	sound3D.at(0)->stop();
	sound3D.erase(sound3D.begin());
}