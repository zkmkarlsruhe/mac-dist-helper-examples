#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main(int argc, char **argv) {

	// run app
	ofSetupOpenGL(640, 512, OF_WINDOW);
	ofRunApp(new ofApp());

	return EXIT_SUCCESS;
}
