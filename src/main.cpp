

#include <iostream>

#include "Image.h"

using namespace std;

int main(int argc, char* argv[]) {
	cout << endl;
	cout << "**********************************" << endl;
	cout << "Image Processor by Oliver Harrison" << endl;
	cout << "**********************************" << endl;

	if (argc < 2) {
		cout << "please specify an image followed by options.\n";
		return 0;
	}

	Image image(argv[1]);

	int arg = 2;

	while(arg < argc) {
		if (string(argv[arg]) == "-i") {		// invert
			arg++;
			cout << "Inverting...\n";
			image.invert();
		}
		else if (string(argv[arg]) == "-g") {		// greyscale
			arg++;
			cout << "Converting to greyscale...\n";
			image.toGreyscale();
		}
		else if (string(argv[arg]) == "-t") {		// threshold
			arg++;
			int t = atoi(argv[arg]);
			if (t > 0) {
				cout << "Applying a thresold of " << t << "...\n";
				image.threshold(t);
				arg++;
			}
			else { // no
				cout << argv[arg] << " doesn't seem to be a very good threshold. Please use a positive integer.\n";
				return 0;
			}
		}

		else if (string(argv[arg]) == "-k") {		// quantize
			arg++;
			int k = atoi(argv[arg]);
			if (k > 0) {
				cout << "Running K-Means with k = " << k << "...\n";
				image.quantize(k);
				arg++;
			}
			else { // no
				cout << argv[arg] << " doesn't seem to be a very good value for k. Please use a positive integer.\n";
				return 0;
			}
		}

		else if (string(argv[arg]) == "-s") {		// sharpen
			arg++;
			cout << "Sharpening...\n";
			image.sharpen();
		}
		else if (string(argv[arg]) == "-b") {		// blur
			arg++;
			cout << "Blurring...\n";
			image.blur();
		}
		else if (string(argv[arg]) == "-e") {		// edges
			arg++;
			cout << "Detecting Edges...\n";
			image.detectEdges();
		}
		else if (string(argv[arg]) == "-m") {		// manual
			arg++;
			cout << "Manual:\n";
			cout << "\t-i  \tinvert\n";
			cout << "\t-g  \tgreyscale\n";
			cout << "\t-t t\tthreshold\n";
			cout << "\t-k k\tk-means quantization\n";
			cout << "\t-b  \tblur\n";
			cout << "\t-s  \tsharpen\n";
			cout << "\t-e  \tdetect edges\n";
		}
		else {
			cout << "Unrecognized command: " << argv[arg] <<  "... Exiting." << endl;
			return 0;
		}
	}

	image.save("output.png");

	return 0;
}

