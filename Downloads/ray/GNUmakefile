#
#  Makefile for fltk applications
#

FLTK_LIBS = -lfltk -lfltk_gl -lfltk_images -lfltk_forms -lpng -lz
X_LIBS = -lXext -lX11 -lXfixes
OPENGL_LIBS = -L/usr/lib/nvidia-340-updates -lGL -lGLU
OTHER_LIBS = -lm -lpthread -ldl

LIBS = $(FLTK_LIBS) $(X_LIBS) $(OPENGL_LIBS) $(OTHER_LIBS)

CFLAGS = -g -std=c++11

CC = g++

.SUFFIXES: .o .cpp .cxx

.cpp.o: 
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $*.o $<

.cxx.o: 
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $*.o $<

ALL.O = src/main.o src/getopt.o src/RayTracer.o \
	src/ui/CommandLineUI.o src/ui/GraphicalUI.o src/ui/TraceGLWindow.o \
	src/ui/debuggingView.o src/ui/glObjects.o src/ui/debuggingWindow.o \
	src/ui/ModelerCamera.o src/ui/CubeMapChooser.o \
	src/fileio/bitmap.o src/fileio/buffer.o \
	src/fileio/pngimage.o \
	src/parser/Token.o src/parser/Tokenizer.o \
	src/parser/Parser.o src/parser/ParserException.o \
	src/scene/camera.o src/scene/light.o\
	src/scene/material.o src/scene/ray.o src/scene/scene.o \
	src/scene/cubeMap.o \
	src/SceneObjects/Box.o src/SceneObjects/Cone.o \
	src/SceneObjects/Cylinder.o src/SceneObjects/trimesh.o \
	src/SceneObjects/Sphere.o src/SceneObjects/Square.o

ray: $(ALL.O)
	$(CC) $(CFLAGS) -o $@ $(ALL.O) $(INCLUDE) $(LIBDIR) $(LIBS)

clean:
	rm -f $(ALL.O)

clean_all:
	rm -f $(ALL.O) ray

