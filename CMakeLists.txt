project(audio LANGUAGES ${RYTHE_LANGUAGE})

rythe_find_sources(sources "${PROJECT_SOURCE_DIR}/src")
add_library(audio ${RYTHE_LIBRARY_TYPE} ${sources})

rythe_add_third_party(
	CURRENT audio
	LIBRARY OpenAL
	PATH "${RYTHE_DIR_ENGINE}/audio/third_party/openal-soft"
	INCLUDE "${RYTHE_DIR_ENGINE}/audio/third_party/openal-soft/include"
	FOLDER "third_party/openal"
	FOLDER_TARGETS OpenAL common alrecord altonegen build_version openal-info ex-common
)

rythe_add_third_party(
	CURRENT audio
	LIBRARY minimp3
	LIBRARY_HEADER_ONLY
	PATH "${RYTHE_DIR_ENGINE}/audio/third_party/minimp3"
	INCLUDE "${RYTHE_DIR_ENGINE}/audio/third_party/minimp3"
	FOLDER "third_party/"
	FOLDER_TARGETS minimp3
)

rythe_configure_module(audio)
rythe_copy_module_output(audio rythe/engine/audio)
