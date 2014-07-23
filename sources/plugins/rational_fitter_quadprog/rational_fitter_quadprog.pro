load(eigen)
load(quadprog)

requires(contains(CONFIG, eigen))
requires(contains(CONFIG, quadprog))


TARGET          = rational_fitter_quadprog
TEMPLATE        = lib
CONFIG         *= plugin

DESTDIR         = ../../build
 
INCLUDEPATH    += ../rational_function \
                  ../rational_data     \
                  ../.. 

HEADERS         = rational_fitter.h
SOURCES         = rational_fitter.cpp

LIBS           += -L../../build        \
                  -lcore	
