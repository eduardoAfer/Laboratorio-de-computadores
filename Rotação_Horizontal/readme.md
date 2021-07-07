PPM - Rotação Horizontal

Pretende-se que implemente um programa em C que faça uma rotação horizontal (rotação de 180 graus em torno de um eixo vertical) de uma imagem em formato PPM. A imagem poderá ser lida da entrada padrão ou de um ficheiro de input (caso seja especificado na linha de comandos). A imagem transformada deverá ser enviada para a saída padrão, ou então, para um ficheiro de output (caso seja especificado na linha de comandos). O ficheiro PPM de output deverá conter apenas um pixel por linha, e não deverá ter comentários.

Nota: Caso não seja possível abrir o(s) ficheiro(s), deverá ser gerada uma mensagem de erro adequada.

Sinopse (assumindo que a aplicação desenvolvida se chama ppm_h_flip):

$ ./ppm_h_flip [input.ppm [output.ppm]]
Exemplos de invocação do aplicativo:

$ ./ppm_h_flip < input.ppm > output.ppm
$ ./ppm_h_flip input.ppm > output.ppm
$ ./ppm_h_flip input.ppm output.ppm
Exemplo de execução 1:

Considere o ficheiro img.ppm:

  Ficheiro img.ppm (ampliado)

A execução do programa:

$ ./ppm_h_flip < img.ppm > img_hflipped.ppm
deverá gerar o ficheiro img_hflipped.ppm:

 

Ficheiro img_hflipped.ppm (ampliado)
Ficheiro img_hflipped.ppm (ampliado)
cujo conteúdo é:

P3
3 2
255
  0   0 255  
  0 255   0 
255   0   0 
  0   0   0 
255 255 255 
255 255   0  
Exemplo de execução 2:

Considere o ficheiro matisse.ppm:

matisse.ppm
matisse.ppm
A execução do programa:

$ ./ppm_h_flip matisse.ppm > matisse_hflipped.ppm
deverá gerar o ficheiro matisse_hflipped.ppm:

 

matisse_hflipped.ppm
matisse_hflipped.ppm