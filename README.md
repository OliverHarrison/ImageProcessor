# ImageProcessor

A C++ demo project that explores image processing alorthims on PNG images.

## Motivation

I made this project to:
* demonstrate my abilities in C++.
* explore the K-Means alogrithm and convolution functions.
* have some fun with images.

## Installation

This project is compiled using g++ and make. To install, clone this repository and run `make` in the project root folder.
This will generate an executeable in the `/bin` directory.

## Execution Example

`./ImageProcessor <image.png> <flags>`

## Flags

The available image processing options are given below. <br/>
Flags may be stacked, for example  `./ImageProcessor image.png -i -k 3 -s` will invert, quantize and sharpen the image in that order.  

Flag | Args | Description | Example Output
---- | ---- | ----------- | --------------
-i | | **Invert** image by finding 255-RGB for each pixel. | ![picture alt](http://www.olivermharrison.com/img/ImageProcessor/invert.png "Invert")
-g | | **Greyscale** conversion by averaging RGB values. | ![picture alt](http://www.olivermharrison.com/img/ImageProcessor/greyscale.png "Greyscale")
-t | t[0, 255] | **Threshold** pixels by setting RGB values < t = 0 and values > t = 255. | ![picture alt](http://www.olivermharrison.com/img/ImageProcessor/threshold.png "Threshold")
-k | k[1, 255] | **Quantize** colours by running K-Means with k centroids. | ![picture alt](http://www.olivermharrison.com/img/ImageProcessor/quantize.png "Quantize")
-b | | **Blur** image by convolving with a Gaussian kernel. | ![picture alt](http://www.olivermharrison.com/img/ImageProcessor/blur.png "Blur")
-s | | **Sharpen** image by convolving with a kernel that emphasizes differences in adjacent pixel values. | ![picture alt](http://www.olivermharrison.com/img/ImageProcessor/sharpen.png "Sharpen")
-e | | **Detect edges** by converting to greyscale and convolving with an edge detection kernel. | ![picture alt](http://www.olivermharrison.com/img/ImageProcessor/edges.png "Invert")


## Tests

This project uses [Catch](https://github.com/philsquared/Catch) for unit testing.
Testing can be conducted by running `make test` in the project root folder.

## License

Please see [Catch](https://github.com/philsquared/Catch) and [LodePNG](https://github.com/lvandeve/lodepng) for their respective licenses. Any other code may be used in anyway you wish.
