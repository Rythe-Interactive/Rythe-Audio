#pragma once
#include <audio/components/audio_listener.hpp>
#include <audio/components/audio_source.hpp>
#include <audio/data/importers/audio_importers.hpp>
#include <audio/systems/audiosystem.hpp>
#include <core/core.hpp>

namespace rythe::audio
{
	class AudioModule : public Module
	{
	public:
		virtual void setup() override
		{
			fs::AssetImporter::reportConverter<mp3_audio_loader>(".mp3");
			fs::AssetImporter::reportConverter<wav_audio_loader>(".wav");

			registerComponentType<audio_source>();
			registerComponentType<audio_listener>();
			reportSystem<AudioSystem>();
		}

		virtual rsl::priority_type priority() override
		{
			return 50;
		}
	};
} // namespace rythe::audio
