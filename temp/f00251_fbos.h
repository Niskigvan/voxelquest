class FBOWrapper
{
public:

	uint color_tex;
	
	//uint color_buf;
	//uint depth_buf;
	uint slot;
	int width;
	int height;
	int bytesPerChannel;
	//bool hasDepth;


	GLint internalFormat;

	unsigned char *pixelsChar;
	float *pixelsFloat;
	bool isFloat;

    FBOWrapper() {}
    ~FBOWrapper() {}
    int init(int _width, int _height, int _bytesPerChannel, int _slot, /*bool _hasDepth,*/ int filterEnum, int clampEnum) {
		width = _width;
		height = _height;
		bytesPerChannel = _bytesPerChannel;
		//hasDepth = _hasDepth;

		int w = width;
		int h = height;

		isFloat = false;

		pixelsChar = NULL;
		pixelsFloat = NULL;


		slot = GL_COLOR_ATTACHMENT0_EXT;

		switch (_slot) {
			case 0:
				slot = GL_COLOR_ATTACHMENT0_EXT;
			break;
			case 1:
				slot = GL_COLOR_ATTACHMENT1_EXT;
			break;
			case 2:
				slot = GL_COLOR_ATTACHMENT2_EXT;
			break;
			case 3:
				slot = GL_COLOR_ATTACHMENT3_EXT;
			break;
			case 4:
				slot = GL_COLOR_ATTACHMENT4_EXT;
			break;
			case 5:
				slot = GL_COLOR_ATTACHMENT5_EXT;
			break;
			case 6:
				slot = GL_COLOR_ATTACHMENT6_EXT;
			break;
			case 7:
				slot = GL_COLOR_ATTACHMENT7_EXT;
			break;
		}

	    

		glGenTextures(1, &color_tex);
		glBindTexture(GL_TEXTURE_2D, color_tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filterEnum);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filterEnum);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, clampEnum);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, clampEnum);
		
	    switch (bytesPerChannel) {
	    	case 1:
	    		internalFormat = GL_RGBA8;
	    		glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
	    		
	    	break;
	    	case 2:
	    		internalFormat = GL_RGBA16;
	            glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, w, h, 0, GL_RGBA, GL_UNSIGNED_SHORT, 0);

	    	break;
	    	case 4:
	    		internalFormat = GL_RGBA32F;
	            glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, w, h, 0, GL_RGBA, GL_FLOAT, 0);
	            isFloat = true;

	    	break;
	    }

	    TOT_GPU_MEM_USAGE += ((float)(w*h*bytesPerChannel*4))/(1024.0f*1024.0f);


	    //
	    /*
	    if (hasDepth) {
	    	glGenRenderbuffersEXT(1, &depth_rb);
	    	glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, depth_rb);
	    	glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT24, w, h);
	    	glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, depth_rb);
	    }
	    */

	    
	    //

		
		glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, slot, GL_TEXTURE_2D, color_tex, 0);
		glBindTexture(GL_TEXTURE_2D, 0);

	    return 1;

	}


	void cpuToGPU() {

		if (pixelsChar == NULL) {
			doTrace("error: null pointer pixelsChar");
			return;
		}

		switch (bytesPerChannel) {
			case 1:

				glBindTexture(GL_TEXTURE_2D, color_tex);
				/*
				glTexSubImage2D(
					GL_TEXTURE_2D,
					0,

					0,
					0,
					width,
					height,
					
					GL_RGBA,
					GL_UNSIGNED_BYTE,
					pixelsChar
				 );
				 */


				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 0);
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixelsChar);

				glBindTexture(GL_TEXTURE_2D, 0);
				
			break;
			case 2:
				doTrace("TODO: implement 16 bit");
			break;
			case 4:
				doTrace("TODO: implement 32 bit");
			break;
		}

		

	}



	void getPixelAtF(FIVector4* fv, int x, int y) {

		if (isFloat) {


			if ( (pixelsFloat == NULL) ) {
				getPixels();
			}

			//a
			//b
			//g
			//r

			fv->setFX(pixelsFloat[ (x + y*width)*4 + 0 ]);
			fv->setFY(pixelsFloat[ (x + y*width)*4 + 1 ]);
			fv->setFZ(pixelsFloat[ (x + y*width)*4 + 2 ]);
			fv->setFW(pixelsFloat[ (x + y*width)*4 + 3 ]);

		}
		else {
			doTrace("Attempted to call getPixelAtF on char buffer.");
		}

	}

	void setAllPixels(int channel, int value) {
		int i;
		int j;
		int x;
		int y;

		for (j = 0; j < height; j++) {
			for (i = 0; i < width; i++) {
				x = i;
				y = j;
				pixelsChar[ (x + y*width)*4 + channel ] = value;
			}
		}
	}

	void setPixelAtC(int x, int y, int channel, unsigned char value) {
		pixelsChar[ (x + y*width)*4 + channel ] = value;
	}


	int getIndex(int xs, int ys) {
		int x = xs;
		int y = ys;

		while (x < 0) {
			x += width;
		}
		while (y < 0) {
			y += height;
		}

		x = x % width;
		y = y % height;

		return x + y*width;
	}

	int getPixelAtIndex(int ind, int channel) {
		return pixelsChar[ind*4 + channel];
	}
	void setPixelAtIndex(int ind, int channel, int val) {
		pixelsChar[ind*4 + channel] = val;
	}
	void orPixelAtIndex(int ind, int channel, int val) {
		pixelsChar[ind*4 + channel] |= val;
	}
	void andPixelAtIndex(int ind, int channel, int val) {
		pixelsChar[ind*4 + channel] &= val;
	}

	int getPixelAtC(int x, int y, int channel) {

		if (!isFloat) {
			if ( (pixelsChar == NULL) ) {
				getPixels();
			}

			return (int)pixelsChar[ (x + y*width)*4 + channel ];

		}
		else {
			doTrace("Attempted to call getPixelAtC on float buffer.");
			return 0;
		}

	}

	float getPixelAtLinear(float xf, float yf, int channel) {
		int x[2];
		int y[2];

		x[0] = floor(xf);
		y[0] = floor(yf);
		x[1] = x[0] + 1;
		y[1] = y[0] + 1;

		float percX = xf - x[0];
		float percY = yf - y[0];
		float percXI = 1.0f-percX;
		float percYI = 1.0f-percY;


		float v0, v1;
		float v2, v3;

		int i;

		for (i = 0; i < 2; i++) {

			while (x[i] < 0) {
				x[i] += width;
			}
			while (y[i] < 0) {
				y[i] += height;
			}

			x[i] = x[i] % width;
			y[i] = y[i] % height;
		}

		v0 = getPixelAtC(x[0],y[0],channel)/255.0f;
		v1 = getPixelAtC(x[1],y[0],channel)/255.0f;
		v2 = getPixelAtC(x[0],y[1],channel)/255.0f;
		v3 = getPixelAtC(x[1],y[1],channel)/255.0f;

		float vFinal = (v0*percXI + v1*percX)*percYI + (v2*percXI + v3*percX)*percY;

		return vFinal;

	}


	void getPixels() {

		glBindTexture(GL_TEXTURE_2D, color_tex);
		GLint numBytes = 0;
		
		//GLint intForm;
		//glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_COMPONENTS, &intForm); // get internal format type of GL texture


		switch(internalFormat) // determine what type GL texture has...
		{
			case GL_RGB:
				numBytes = width * height * 3;
			break;
			case GL_RGBA:
				numBytes = width * height * 4;
			break;
			case GL_RGBA8:
				numBytes = width * height * 4;
			break;
			//case GL_RGBA16:
			//
			//break;
			case GL_RGBA32F:
				numBytes = width * height * 4 * 4;
			break;

			default:
				doTrace("Unsupported Format Type");
				return;
			break;
		}

		if (numBytes) {

			if (isFloat) {

				if (pixelsFloat == NULL) {
					pixelsFloat = (float*)malloc(numBytes);
				}
				
				glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_FLOAT, pixelsFloat);
			}
			else {

				if (pixelsChar == NULL) {
					pixelsChar = (unsigned char*)malloc(numBytes);
				}
				glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixelsChar);
			}

			
		}

		glBindTexture(GL_TEXTURE_2D, 0);


	}


};


class FBOSet
{
public:
	int numBufs;
	int width;
	int height;
	int bytesPerChannel;

	uint depth_rb;

	GLuint mFBO;

	FBOWrapper* fbos;

	bool hasDepth;

    FBOSet() {}
    ~FBOSet() {}

    FBOWrapper* getFBOWrapper(int offset) {
    	return &(fbos[offset]);
    }

    void init(int _numBufs, int _width, int _height, int _bytesPerChannel, bool _hasDepth, int filterEnum=GL_NEAREST, int clampEnum=GL_CLAMP_TO_EDGE) {
		int i;

		hasDepth = _hasDepth;

		numBufs = _numBufs;
		height = _height;
		width = _width;
		bytesPerChannel = _bytesPerChannel;

		fbos = new FBOWrapper[numBufs];


		glGenFramebuffersEXT(1, &mFBO);
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, mFBO);

		for (i = 0; i < numBufs; i++) {
			fbos[i].init(width, height, bytesPerChannel, i, /*hasDepth,*/ filterEnum, clampEnum);
		}


		if (hasDepth) {
			glGenRenderbuffersEXT(1, &depth_rb);
			glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, depth_rb);
			glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT24, width, height);
			glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, depth_rb);
		}


		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	}
    void bind(int doClear) {

		//setWH(width, height);

		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, mFBO);

		GLenum buffers[] = {GL_COLOR_ATTACHMENT0_EXT, GL_COLOR_ATTACHMENT1_EXT, GL_COLOR_ATTACHMENT2_EXT, GL_COLOR_ATTACHMENT3_EXT, GL_COLOR_ATTACHMENT4_EXT};
		glDrawBuffers(numBufs, buffers);

		if (doClear) {
	    	glClearColor(0.0,0.0,0.0,0.0);
	    	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	    }

	}
	/*
    void setWH(int w, int h) {
		glViewport(0,0,w,h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
		glMatrixMode(GL_MODELVIEW);
		glMatrixMode (GL_MODELVIEW);
		glLoadIdentity ();
		glMatrixMode (GL_PROJECTION);
		glLoadIdentity ();
	}
	*/
    void copyFromMem(int ind, unsigned char* dat) {

		//glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, mFBO);

	    glBindTexture(GL_TEXTURE_2D,fbos[ind].color_tex);

	    //glTexSubImage2D(GLenum target​, GLint level​, GLint xoffset​, GLint yoffset​, GLsizei width​, GLsizei height​, GLenum format​, GLenum type​, const GLvoid * data​);

		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, dat);
		//glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, fbos[ind].slot, GL_TEXTURE_2D, fbos[ind].color_tex, 0);
		//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glBindTexture(GL_TEXTURE_2D,0);

		//glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	}
}; 
