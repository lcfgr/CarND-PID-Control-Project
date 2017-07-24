# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Project Description

In this project we implement a PID controller which is used to control the steering of an autonomous vehicle. The udacity 
simulator is used as a testing enviroment of the performance of our controller. After the basic program is created, the parameters of the PID
controller are tuned.
 
The 3 parameters are chosen as following:

1. The Proportional coefficient is relatively small (0.12), to avoid oscillations that can drive the car out of the track.
2. The Differential coefficient is relatively high (1.1) in comparison to Proportional coefficient, so that there is minimal oscillation and to converge fast on turns
3. The Integral coefficient is zero (0)), because there was no systemic bias in the simulated auto and even a slight increase 
in this coefficient created problems, probably due to the left turn bias of the track which created a constant increase in this value.


The speed of the car is limited to 50 Mph where the performance of the controller is within the expected behaviour.
Also the acceleration of the car is related with the total error of the PID controller. The bigger the error the smaller the acceleration.

the demo of the PID controller test is here: [PID test](https://github.com/lcfgr/CarND-PID-Control-Project/blob/master/PID_controller_test.mp4)


## Reflection

The manual fine-tuning of this PID controller was relatively easy. However the problem is relatively easy, since we do not have any systematic bias. 
In this case it would be challenging, since even a slight existance of integral coefficient creates problems.
  
The next step is to test the twiddle algorithm for achiving real-time fine tuning of the coefficients. Also a more sophisticated PID throttle controller could be 
implemented, which likely would produce better performance.


