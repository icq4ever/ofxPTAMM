
#include "ofMain.h"
#include "ofxPTAMM.h"

//#define CAMERACALIBRATION
#ifdef CAMERACALIBRATION
#include "ofxCameraCalibrator.h"
#endif

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    void ofAppPressed  (int ofApp);
    void ofAppReleased(int ofApp);
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased();
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    
    ofVideoGrabber			grabber;
    ofImage                 video;
    ofxPTAMM				ptamm;
#ifdef CAMARACALIBRATION
    ofxCameraCalibrator     ccam;
#endif
    
    ofLight                 light;
    ofCamera                cam;
    ofImage                 logo;
    
    int			camWidth, camHeight;
};
