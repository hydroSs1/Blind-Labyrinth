
# Blind Labyrinth 
<p align="center">
 <img alt="Languages" src="https://img.shields.io/badge/Languages-C | Assembly-orange"/>
 <img alt="Status" src="https://img.shields.io/badge/development-completed-green"/>
</p>

<p align="center">
  <img src="screenshots/animation.gif" alt="animated" />
</p>

Project for the Computer Architectures course at Politecnico di Torino.
Implementation of the game Blind Labyrinth over the NPX LandTigerBoard.

## Brief description

The user drives a robot equipped with a proximity sensor detecting obstacles to the exit.  The robot covers 1 slot per second.

The game is available in two versions:

- **basic version** : the user controls the robot only using buttons KEY1, KEY2 and INT0 to move or rotate the player. The LEDs blink at different frequencies according to current direction and distance from obstacle.

- **advanced version** : the user drives the robot using the joystick. The map is displayed on the touchscreen display. The proximity sensor only displays obstacles in the nearby. Pressing the joystick, the robot switches mode (and color): now it only reveals obstacles in the nearby without moving. Pressing again it goes back to moving mode.

  <div align="center">
      <img width="180px" height="250px" src="screenshots/fig1.png" </img> &nbsp &nbsp
      <img width="180px" height="250px" src="screenshots/fig2.png" </img> &nbsp &nbsp
      <img width="180px" height="250px" src="screenshots/fig3.png" </img> &nbsp &nbsp
  </div>
