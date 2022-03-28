project(audio LANGUAGES ${RYTHE_LANGUAGE})

rythe_find_sources(sources "${PROJECT_SOURCE_DIR}/src")
add_library(audio ${RYTHE_LIBRARY_TYPE} ${sources})

rythe_configure_module(audio)
rythe_copy_module_output(audio rythe/engine/audio)
