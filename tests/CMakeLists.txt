
add_custom_target(mathutils_tests)

set(TESTS
        test_unit
        test_angles
        test_interp1d
        test_lookup_table
        test_interp2d
        test_vector2d
        test_vector3d
        test_transform3d
        test_matrixMN
        test_integration1d
        test_fft
        test_convolution
        test_spline
        test_vectorN
		test_geometry        
		)

IF(MSVC)
    ADD_DEFINITIONS("/MP")
    MESSAGE(STATUS "MSVC /MP option activated")
ENDIF(MSVC)

foreach(test ${TESTS})

    message(STATUS "...add ${test}")

    add_executable(${test} ${test}.cpp)
    target_link_libraries(${test} MathUtils::MathUtils Eigen3::Eigen)

    add_dependencies(mathutils_tests ${test})

endforeach()
