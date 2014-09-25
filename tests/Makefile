all: Tratamento_imagem.o constroi_biblioteca.o
	g++ -o constroi_biblioteca Tratamento_imagem.o constroi_biblioteca.o -lopencv_core -lopencv_imgproc -lopencv_highgui

Tratamento_imagem.o: Tratamento_imagem.cc
	g++ -c Tratamento_imagem.cc

constroi_biblioteca.o: constroi_biblioteca.cc
	g++ -c constroi_biblioteca.cc

clean:
	rm constroi_biblioteca *.o
