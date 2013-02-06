TARGET          = rational_fitter_quadprog
TEMPLATE        = lib
CONFIG         *= qt         \
                  plugin     \
						eigen      \
						quadprog 

DESTDIR         = ../../build
 
INCLUDEPATH    += ../rational_function \
                  ../rational_data     \
                  ../.. 

HEADERS         = rational_fitter.h
SOURCES         = rational_fitter.cpp

LIBS           += -L../../build        \
						-lrational_function	\
						-lrational_data

#QMAKE_CXXFLAGS += -fPIC

