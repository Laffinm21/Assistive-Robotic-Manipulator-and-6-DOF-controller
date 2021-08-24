# Assistive-Robotic-Manipulator-and-6-DOF-controller

Details on this project can also be found on my [Hackaday post](https://hackaday.io/project/181205-assistive-robotic-manipulator-and-6-dof-controller).

## Repository Architecture
This repo is separated into the following folders:
- Mechanical design files
- Software
- Documentation

![Example Range of Motion Video](https://drive.google.com/file/d/1MQTKNlysBVVUuPiLPVbzMV4yg6Pk1A4A/view?usp=sharing)

## Project Background
For those with upper extremity impairments that affect strength and reach, performing simple physical activities of daily life can prove to be insurmountable. Assistive robotic arms have been shown to be effective tools to increase user autonomy within these tasks and can significantly reduce caregiver intervention.[[1]](https://pubmed.ncbi.nlm.nih.gov/22275600/) 

User interfaces for commercial assistive robot arms vary between products, however most are centered around standard wheelchair joysticks or keypads. Such interfaces can lead to a significant bottleneck in user efficiency that is caused by the reality of controlling a high-dimensional robot arm with a low-dimensional "conventional" joystick. That is, without the use of additional intelligent control algorithms, auxiliary buttons and low DoF joysticks are used to switch between control modes to perform compound movements. 

 Such operation is simple however, small delays from switching joints can quickly accumulate into a significant amount of time for the user. The this project is an investigation into the viability of concurrent joint operation, opposed to consecutive operation of individual joints as seen in many current systems. 

## System Overview
![Robot Arm and Controller Joystick](https://cdn.hackaday.io/images/5503631629755416228.jpg)


## Electronics Functional Block Diagram
![Functional Block Diagram](https://cdn.hackaday.io/images/384401629052787796.png)

