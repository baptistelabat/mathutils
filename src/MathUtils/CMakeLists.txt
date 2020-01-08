
# HEADER_FILES
set(MATHUTILS_HEADERS
        Constants.h
        Angles.h
        Unit.h
        Interp.h
        Interp1d.h
        LookupTable1D.h
        Interp2d.h
        LookupTable2D.h
        Maths.h
        VectorGeneration.h
        Check.h
        Vector2d.h
        Vector3d.h
        Transform3d.h
        Matrix.h
        Integration1d.h
        FFT.h
        Complex.h
        StdVector.h
        Functions.h
        Convolution.h
        VectorN.h
		Geometry.h
        )


# Building target
add_library(MathUtils INTERFACE)
target_link_libraries(MathUtils INTERFACE Eigen3::Eigen Boost::boost)

add_library(MathUtils::MathUtils ALIAS MathUtils)

target_include_directories(MathUtils INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include>)
#target_include_directories(MathUtils INTERFACE
#        ${PROJECT_SOURCE_DIR}/src
#        )


#set_target_properties(MathUtils PROPERTIES
#        VERSION ${MathUtils_VERSION})

include(GNUInstallDirs)
#message(${CMAKE_INSTALL_LIBDIR})
install(TARGETS MathUtils EXPORT MathUtils-targets
        DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(FILES ${MATHUTILS_HEADERS}
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/MathUtils)
