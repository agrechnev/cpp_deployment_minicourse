cmake_minimum_required(VERSION 3.10)
project(tflite1)
set(CMAKE_CXX_STANDARD 17)

# Find TFLITE by hand
# Important: You must configure with
# cmake -DTF_ROOT=<...> ..
# For example: -DTF_ROOT=${HOME}/w/misc_codes/tf_root
# Ugly, but we don't want to waste time by writing a script to copy header files and libs from 100500 subdirectories
message("TF_ROOT=${TF_ROOT}")
link_directories(${TF_ROOT}/tflite_build)
link_directories(${TF_ROOT}/tflite_build/_deps/xnnpack-build)
link_directories(${TF_ROOT}/tflite_build/pthreadpool)
link_directories(${TF_ROOT}/tflite_build/_deps/cpuinfo-build)
link_directories(${TF_ROOT}/tflite_build/_deps/flatbuffers-build)
link_directories(${TF_ROOT}/tflite_build/_deps/fft2d-build)
link_directories(${TF_ROOT}/tflite_build/_deps/ruy-build/ruy)
link_directories(${TF_ROOT}/tflite_build/_deps/farmhash-build)
message("")
include_directories(${TF_ROOT}/tensorflow)
include_directories(${TF_ROOT}/tflite_build/flatbuffers/include)
set(TFLITE_LIBS
        tensorflow-lite XNNPACK pthreadpool cpuinfo flatbuffers
        fft2d_fftsg fft2d_shrtdct fft2d_fftsg2d fft2d_fftsg3d fft2d_alloc fft2d_fft4f2d
        ruy_context ruy_have_built_path_for_avx2_fma ruy_pack_avx512 ruy_wait ruy_cpuinfo ruy_apply_multiplier ruy_trmul ruy_prepacked_cache
        ruy_kernel_arm ruy_thread_pool ruy_wait ruy_prepare_packed_matrices
        ruy_allocator ruy_pack_avx2_fma ruy_system_aligned_alloc ruy_pack_arm ruy_tune ruy_blocking_counter ruy_ctx ruy_kernel_avx512 ruy_block_map ruy_have_built_path_for_avx
        ruy_have_built_path_for_avx2_fma ruy_context_get_ctx ruy_denormal ruy_frontend ruy_kernel_avx2_fma  ruy_kernel_avx ruy_have_built_path_for_avx512 ruy_pack_avx
        farmhash
        )


# Find OpenCV
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(tflite1 tflite1.cpp)
target_link_libraries(tflite1  ${TFLITE_LIBS} ${OpenCV_LIBS})
