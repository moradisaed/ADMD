# ADMD
Absolute directional mean difference (ADMD) algorithm for small infrared target detection

Both MATLAB and OpenCV implementation of the following paper:
Fast and robust small infrared target detection using absolute directional mean difference algorithm

If you are using this code in your researches, kindly cite the following paper:

[Moradi, Saed, Payman Moallem, and Mohamad Farzan Sabahi. "Fast and robust small infrared target detection using absolute directional mean difference algorithm." Signal Processing (2020)](https://www.sciencedirect.com/science/article/abs/pii/S016516842030270X)

## MATLAB

You can find the single-scale (7by7) implementation of the ADMD algorithm in MATLAB subdirectory. The multi-scale version can be constructed by easily constructed using max selection among different scales (see the paper for further information). To achieve saliency-map, just pass the image though **AdMD7_eff** function:

    h<sub>&theta;</sub>(x) = &theta;<sub>o</sub> x + &theta;<sub>1</sub>x

```
Filtered_image = AdMD7_eff( img)
```

## OpenCV



The code is implemented using OpenCV 3.4 in Ubuntu 18.04 environment. It is not tested for other OpenCV versions, but it should work. 
### Prerequisites
[OpenCV](http://opencv.org/)

### Setup
Build OpenCV from source (if you want to enable QT option to zoom on images and see the pixels value), or just simply use the following command in terminal:

```shell
$ sudo apt install libopencv-dev python3-opencv
```






