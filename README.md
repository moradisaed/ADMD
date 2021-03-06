# ADMD
Absolute directional mean difference (ADMD) algorithm for small infrared target detection

Both MATLAB and OpenCV implementations of the following paper:
Fast and robust small infrared target detection using absolute directional mean difference algorithm

If you are using these codes in your researches, kindly cite the following paper:

[Moradi, Saed, Payman Moallem, and Mohamad Farzan Sabahi. "Fast and robust small infrared target detection using absolute directional mean difference algorithm." Signal Processing 177 (2020): 107727](https://www.sciencedirect.com/science/article/abs/pii/S016516842030270X)

## MATLAB

You can find the single-scale (7by7) implementation of the ADMD algorithm in MATLAB subdirectory. The multi-scale version can be easily constructed by max selection among different scales (see the paper for further information). To achieve saliency-map, just pass the test image through **AdMD7_eff** function:

```matlab
test_img=double(test_img);
Filtered_image = AdMD7_eff(test_img);
```

## OpenCV

Both single and multi-scale implementation of the ADMD algorithm can be found in CPP subdirectory. 
The codes are implemented using OpenCV 3.4 in Ubuntu 18.04 environment. 

### Prerequisites
[OpenCV](http://opencv.org/)

### Setup
Build OpenCV from source (if you want to enable QT option to zoom on images and see the pixels value), or just simply use the following command in terminal:

```shell
$ sudo apt install libopencv-dev python3-opencv
```






