# Laboratorio-de-computadores <br />  Project in C language that works on ppm pictures #



 ### [ppm_h_flip](https://github.com/eduardoAfer/Laboratorio-de-computadores/blob/main/Rotação_Horizontal/ppm_h_flip.c) which flips a ppm image 180º horizontally ### 


Synopse

<pre><code>$ ppm_h_flip [input.ppm [output.ppm]]
</code></pre>
Use examples

<pre><code>$ ./ppm_h_flip < input.ppm > output.ppm
$ ./ppm_h_flip input.ppm > output.ppm
$ ./ppm_h_flip input.ppm output.ppm</code></pre>


### [ppm_v_flip](https://github.com/eduardoAfer/Laboratorio-de-computadores/blob/main/Rotação_Vertical/ppm_v_flip.c) which flips a ppm image 180º verticall ###

Synopse:

<pre><code>$ ppm_v_flip [input.ppm [output.ppm]]</code></pre>
Use examples:

<pre><code>$ ./ppm_v_flip < input.ppm > output.ppm
$ ./ppm_v_flip input.ppm > output.ppm
$ ./ppm_v_flip input.ppm output.ppm </code></pre>


### [ppm_d_flip](https://github.com/eduardoAfer/Laboratorio-de-computadores/blob/main/PROJETO/operacao3/rotD.c) which flips a ppm image diagonally (from top-left to low-right) ###

Synopse

<pre><code>$ ppm_d_flip [input.ppm [output.ppm]]</code></pre>
Use examples:

<pre><code>$ ./ppm_d_flip < input.ppm > output.ppm
$ ./ppm_d_flip input.ppm > output.ppm
$ ./ppm_d_flip input.ppm output.ppm </code></pre>


### [ppm_addRGB](https://github.com/eduardoAfer/Laboratorio-de-computadores/blob/main/PROJETO/operacao4/c2color.c) which adjusts the RGB components of the ppm image. ###

Ajusts the RGB components according to the arguments given at launch. For the adjustment triplet (dR, dG, dB), the colour values of each pixel i become (Ri + dR, Gi + dG, Bi + dB)

Synopse:

<pre><code>$ ppm_addRGB dR dG dB [input.ppm [output.ppm]]</code></pre>
Use examples:

<pre><code>$ ./ppm_addRGB +10 -1 +50 < input.ppm > output.ppm
$ ./ppm_addRGB -20 +30 0 input.ppm > output.ppm
$ ./ppm_addRGB 0 0 +100 input.ppm output.ppm</code></pre>


### [ppm_grayscale](https://github.com/eduardoAfer/Laboratorio-de-computadores/blob/main/PROJETO/operacao5/gray.c) which generates a grayscale version of a ppm image ###

The value of each pixel (R,G,B) becomes (G,G,G), where G = 0.2126R + 0.7152G + 0.0722B
Synopse:

<pre><code>$ ppm_grayscale [input.ppm [output.ppm]]</code></pre>
Use examples:

<pre><code>$ ./ppm_grayscale < input.ppm > output.ppm
$ ./ppm_grayscale input.ppm > output.ppm
$ ./ppm_grayscale input.ppm output.ppm</code></pre>


### [ppm_bw which](https://github.com/eduardoAfer/Laboratorio-de-computadores/blob/main/PROJETO/operacao6/pb.c) generates a black and white version ppm image, according to a color threshold ###

The value of each pixel (R,G,B) i becomes (MAXCOLOR,MAXCOLOR,MAXCOLOR), if grayscale value of i, G > threshold. (0,0,0) if otherwise.
Synopse:

<pre><code>$ ppm_bw threshold [input.ppm [output.ppm]]</code></pre>
where 0 < threshold < MAXCOLOR
Use examples:

<pre><code>$ ./ppm_bw 64 < input.ppm > output.ppm
$ ./ppm_bw 77 input.ppm > output.ppm
$ ./ppm_bw 100 input.ppm output.ppm</code></pre>


### [ppm_rot_right](https://github.com/eduardoAfer/Laboratorio-de-computadores/blob/main/PROJETO/operacao7/roda90.c) which rotates a ppm image by 90º to the right ###

Synopse:

<pre><code>$ ppm_rot_right [input.ppm [output.ppm]]</code></pre>
Use examples:

<pre><code>$ ./ppm_rot_right < input.ppm > output.ppm
$ ./ppm_rot_right input.ppm > output.ppm
$ ./ppm_rot_right input.ppm output.ppm</code></pre>


### [ppm_rot_left](https://github.com/eduardoAfer/Laboratorio-de-computadores/blob/main/PROJETO/operacao8/R90esq.c) which rotates a ppm image by 90º to the left ###

Synopse

<pre><code>$ ppm_rot_left [input.ppm [output.ppm]]</code></pre>
Use examples

<pre><code>$ ./ppm_rot_left < input.ppm > output.ppm
$ ./ppm_rot_left input.ppm > output.ppm
$ ./ppm_rot_left input.ppm output.ppm</code></pre>


### [ppm_addBorder](https://github.com/eduardoAfer/Laboratorio-de-computadores/blob/main/PROJETO/operacao9/moldura2.c) which adds a frame to a ppm image ###

Synopse:

<pre><code>$ $ ./ppm_addBorder width R G B [input.ppm [output.ppm]]</code></pre>
Use examples:

<pre><code>$ ./ppm_addBorder width R G B < input.ppm > output.ppm
$ ./ppm_addBorder width R G B input.ppm > output.ppm
$ ./ppm_addBorder width R G B input.ppm output.ppm</code></pre>



