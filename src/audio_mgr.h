#pragma once
#include "irrKlang.h"
#include <iostream>
#include "Vector.h"
#include "ik_ISoundEngine.h"

namespace Aftr
{
	class audio_mgr
	{
		private:
			irrklang::ISoundEngine* engine = nullptr;
			std::vector < irrklang::ISound*> sound2D;
			std::vector < irrklang::ISound*> sound3D;
		
		public:
			static audio_mgr* init();
			void audio_mgr::set_audio_engine(irrklang::ISoundEngine* audio_engine);
			void audio_mgr::play_2D_audio(const char* audio_file,bool loop, bool pause, bool track);
			void audio_mgr::play_3D_audio(const char* audio_file, Aftr::Vector location, bool loop, bool pause, bool track);
			irrklang::vec3df audio_mgr::vector_con(Vector location);
			irrklang::ISoundEngine* audio_mgr::get_audio_engine();
			std::vector<irrklang::ISound*> audio_mgr::get_2D_audio();
			std::vector<irrklang::ISound*> audio_mgr::get_3D_audio();
			void audio_mgr::stop_2d_audio();
			void audio_mgr::stop_3d_audio();
	};
}

