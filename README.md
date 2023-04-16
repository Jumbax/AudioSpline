# AudioSpline
Hello! This is a plugin that I made for Unreal Engine 5 in C++.
Here you will find an Audio Spline, a common useful tool for making an audio source follow an Actor without exiting from an precalculated path.

![giphy](https://user-images.githubusercontent.com/70896924/232324519-67e78d06-e284-4e7d-89f8-70d28517e8ec.gif)

You will find a window and a few commands for debug aswell.

---

### Features:

- Use Tick or a custom frequency for Update the movement
- Active/Deactive the Actor as needed to avoid useless update
- Use a Sphere Collider to Active/Deactive automatically
- Window with some buttons for debug
- A few commands for debug

---

### Usage:

- Download the content from [here](https://github.com/Jumbax/AudioSpline/releases/tag/v1.0.0)
- Drag and drop the folder inside your plugin folder

![Cattura2](https://user-images.githubusercontent.com/70896924/232051027-77b92daf-0ef9-478e-9502-654a4f8fe528.png)

(If you haven’t this folder create a plugin following this guide to create it: https://docs.unrealengine.com/4.27/en-US/ProductionPipelines/Plugins/)
- Add the string “AudioSplinePlugin” to your Build.cs file like this
![Cattura4](https://user-images.githubusercontent.com/70896924/232074007-b3107bff-a074-43d4-aa60-784c1d14c0a5.png)
- In Unreal Engine Content Browser
- In the folder Plugin/AudioSplinePluginC++Classes/AudioSplinePlugin/Public you will find the Actor
- In the folder Plugin/AudioSplinePluginContent you will find the Blueprint
- Choose the right one for you and put it on scene
- Select the one you choosed and selecting the Spline Component add some Spline Point. (Follow this guide if you are not familiar with this: https://docs.unrealengine.com/4.27/en-US/BuildingWorlds/BlueprintSplines/HowTo/EditSplineComponentInEditor/).
- Pass to the AudioSpline the Actor you want the spline will follow

![Cattura6](https://user-images.githubusercontent.com/70896924/232053383-e418d542-b230-4f22-92b6-9ec641945aa3.png)

- Assign an audio to the AudioComponent and set his Attenuation for a good result
- Remember to set your custom Sphere Radius if you are using the Sphere Collision

VIDEO

---

### Properties:

- AutoStart: If true the AudioSpline runs at start
- ActorToFollow: The Actor that AudioSpline follows
- Frequency: The Frequency that will be updated if the UseTick is false
- UseTick: You can choose if updating the movement using tick or with a custom frequency
- IsActive: Is Telling you if the AudioSpline is currently active
- UseSphereCollision: If SphereCollision is true when your Actor will collide with the SphereComponent the AudioSpline will Start/Stop to move and follow him

---

### Functions:

- GetFrequency(): return the currently updating frequency
- SetFrequency(const float NewFrequency): set the custom updating frequency
- GetActive(): return true if the AudioSpline is Active or false if isn’t
- SetActive(const bool IsActive): set active the AudioSpline make it follow your actor
- GetUseTick(): return true if it’s using Tick or false if it’s using the custom frequency
- SetUseTick(const bool UseTick): set true if you want to use the Tick or false if you want to use a custom frequency
- GetUseSphereCollision(): return true if it’s using the SphereCollision so if your actor will collide to the sphere the AudioSpline will active/deactive. If it’s false it does nothing
- SetUseSphereCollision(const bool UseSphereCollision): set true if you want to use the SphereComponent to automatically active/deactive the AudioSpline when your actor collide with that
- ToggleIsActive(): toggle the AudioSpline IsActive, if it’s true will became false and viceversa
- ToggleUseTick(): toggle the AudioSpine UseTick, if it’s true will became false and viceversa
- ToggleUseSphereCollision(): toggle the AudioSpline UseSphereCollision, if it’s true will became false and viceversa

---

### Window:
![Cattura8](https://user-images.githubusercontent.com/70896924/232054171-06bfd78d-2bdb-4a81-8498-8917bfd60018.png)
- ToggleIsActive: Call ToggleIsActive()
- ToggleUseTick: Call ToggleUseTick()
- ToggleUseSphereCollision: Call ToggleUseSphereCollision()

---

### Commands:

- AudioSpline Tab: Open the AudioSpline window
- AudioSpline ToggleIsActive: Call ToggleIsActive()
- AudioSpline ToggleUseTick: Call ToggleUseTick()
- AudioSpline ToggleUseSphereCollision: Call ToggleUseSphereCollision()

---

### Video:

https://user-images.githubusercontent.com/70896924/232325130-81f13d8b-60a0-4d55-8521-c558f2c724a1.mp4
