# ImageProcessor

## Synopsis

A C++ demo project that explores image processing alorthims on PNG images.

## Execution Example

`./ImageProcessor <image.png> <flags>`

## Motivation

I made this project for the following reasons:
* To demonstrate my abilities in C++.
* To explore the K-Means alogrithm and convolution functions.
* To have some fun with images.

## Installation

This project is compiled using g++ and make. To install, clone this repository and run `make` in the project root folder.
This will generate an executeable in the /bin directory. Alternatively, just execute the appopriate binary for your OS provided in /bin.

## Flags

The available image processing options are given below. <br/>
Flags may be stacked, for example  `./ImageProcessor image.png -i -k 3 -s` will invert, quantize and sharpen image.png int that order.  

Flag | Args | Description | Example Output
---- | ---- | ----------- | --------------
-i   |      | **Invert**      | ![picture alt](http://www.olivermharrison.com/img/ImageProcessor/invert.png "Invert")
-g	 |		  | **Greyscale** | ![picture alt](http://www.olivermharrison.com/img/ImageProcessor/greyscale.png "Greyscale")
-t   | t[0, 255]	| **Threshold** - Apply a threshold of t where colour values <t are set to 0, and colours >t set to 255. | ![picture alt](http://www.olivermharrison.com/img/ImageProcessor/threshold.png "Threshold")
-k   | k(0, inf)    | **Quantize** colours by running K-Means with k centroids. | ![picture alt](http://www.olivermharrison.com/img/ImageProcessor/quantize.png "Quantize")
-b   | 	    | **Blur** | ![picture alt](http://www.olivermharrison.com/img/ImageProcessor/blur.png "Blur")
-s   | 	    | **Sharpen** | ![picture alt](http://www.olivermharrison.com/img/ImageProcessor/sharpen.png "Sharpen")
-e   |      | **Detect edges** | ![picture alt](http://www.olivermharrison.com/img/ImageProcessor/edges.png "Invert")


## Tests

This project makes use of [Catch](https://github.com/philsquared/Catch) to conduct unit testing.<br/>
Testing may be executed by running `make test` in the project root folder.

## License

You are free to use this software in anyway you wish. 