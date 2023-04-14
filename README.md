# AudioSpline
Hello, in this plugin you will find an Audio Spline, a common useful tool for making an audio source follow an Actor without exiting from an precalculated path.

GIF

You will find a window and a few commands for debug aswell.

### Features:

- Use Tick or a custom frequency for Update the movement
- Active/Deactive the Actor as needed to avoid useless update
- Use a Sphere Collider to Active/Deactive automatically
- Window with some buttons for debug
- A few commands for debug

### Usage:

- Download the content from LINK
- Drag and drop the folder to your plugin folder.
IMMAGINE
(If you haven’t this folder create a plugin following this guide to create this: LINK ALLA GUIDA PER CREARE UN PLUGIN)
- Add the string “AudioSplineTool” to your Build.cs file like this
IMMAGINE
- In the folder Plugin/AudioSplineTool C++Classes/AudioSplineTool/Public you will find the Actor
- In the folder Plugin/AudioSplineTool Content you will find the Blueprint.
- Choose the right for you and put on scene
- Select the one you choosed and selecting the Spline Component add some Spline Point.
Follow this guide if you are not familiar with this: LINK ALL’USO DELLO SPLINE COMPONENT.
- Pass to the AudioSpline the Actor you want the spline will follow.
IMMAGINE

### Properties:

- AutoStart: If true the AudioSpline runs at start
- ActorToFollow: The Actor that AudioSpline follows
- Frequency: The Frequency that will be updated if the UseTick is false
- UseTick: You can choose if updating the movement using tick or with a custom frequency
- IsActive: Is Telling you if the AudioSpline is currently active
- UseSphereCollision: If SphereCollision is true when your Actor will collide with the SphereComponent the AudioSpline will Start/Stop to move and follow him

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

### Window

- ToggleIsActive: Call ToggleIsActive().
- ToggleUseTick: Call ToggleUseTick().
- ToggleUseSphereCollision: Call ToggleUseSphereCollision().

### Commands

- AudioSplineTabs: Open the AudioSpline Tab.
- AudioSpline ToggleIsActive: Call ToggleIsActive()
- AudioSpline ToggleUseTick: Call ToggleUseTick().
- AudioSpline ToggleUseSphereCollision: Call ToggleUseSphereCollision().

VIDEO
