all: teste.o Tratamento_imagem.o
	g++ -g -o teste Tratamento_imagem.o teste.o -lopencv_core -lopencv_imgproc -lopencv_highgui 

Tratamento_imagem.o: Tratamento_imagem.cc
	g++ -g -c Tratamento_imagem.cc

teste.o: teste.cc
	g++ -g -c teste.cc

clean:
	rm teste *.o
