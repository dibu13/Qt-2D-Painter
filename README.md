# Qt-2D-Painter
![Painter 2D](https://i.gyazo.com/39c4f08a9b451f19ae7875e9407211f9.png)

2D vector shapes painter with GameObjects & components hierarchy.
## Contributors
* Rubén Sardón - [@cumus](https://github.com/cumus)
* Daniel Triviño - [@dibu13](https://github.com/dibu13)
## Features
### Main menu bar
![Toolbar](https://i.gyazo.com/c196d6a8679385f334744755f500ca00.png)

Icons menu bar with the most important actions.
* #### New Scene
Opens a new scene.
* #### Open Scene
Opens a saved scene using QFileDialog to choose .scene file.  If the scene is empty, a QMessageBox will apear instead.
* #### Save Scene
Saves the scene in its current state using QFileDialog. If the scene is empty, a QMessageBox will apear instead.
* #### Open readme
Opens the readme file in the default browser using [static] bool QDesktopServices::openUrl(const QUrl &url).
### Hierarchy
![Hierarchy](https://i.gyazo.com/f3b2d9c10d94f554c504b49086b59f41.png)

* #### List Widget
Here you can see the existing entities and you can select them by clicking on them. The inspector's values will change to those of the selected game object. 
* #### Add Entity
Adds an entity with the name of the input text to the scene. The name given can't be blank. Game object added will have a Rect Transform Component and a Shape Renderer Component with default values.
* #### Remove Entity
Removes the selected entity from the scene.
* ### BackGround Color
You can change the scene's background color.
### Inspector
![Inspector](https://i.gyazo.com/13eb7e3cc506a461b20460df117eaf6d.png)

Shows the information of the selected entity of all its components.
* #### GameObject
The CheckBox activates or deactivate the entity. If an entity is deactivate it won't be drawn in the scene. The label shows the game objects' name.
* #### Component Tranform
Allows to edit the position and the scale of the entity
* #### Component Render
  * **Shape**: Selects the shape to draw, circle or rectangle.
  * **Size**: Modifies the size of the shape.
  * **Fill color**: Picks the fill color.
  * **Stroke color**: Select the stroke line color.
  * **Stroke Thickness**: Modifies the thickness of the strokes line.
  * **Stroke Style**: Select the line style. None, Solid, Dash, Dot, Dash dot and Dash dot dot.
### Scene
![Scene](https://i.gyazo.com/5d16f895f34892ae67bd38738fbaced2.png)

Draws all the entities. Renders the background color and adds a border to mark the drawing zone.
## QT Features implemented
* **Slots**: they connect ui user actions to our logic.
* **QApplication** & **QMainWindow**: Used by MainWindow as the parent widget;
* **QToolBar** &  **QMenuBar**: Include icons for actions: New Scene, Load Scene, Save Scene and Open Read.ME.
* **QDesktopServices** & **QUrl**: Used to open Read.ME in default browser.
* **QMessageBox**: Shown when loading or saving empty scenes.
* **QFileDialog**, **QFile** & **QDataStream**: Used to save and load .scene files.
* **QDockWidget**: Docks the Hierarchy and Inspector uis.
* **QListWidget** & **QListWidgetItem**: used by Hierarchy to show scene's game objects.
* **QPainter**: used by Component Shape Renderer to Draw the scene's game objects.
* **QColorDialog**: used to edit a QColor in Component Shape Renderer and the scene's background color.
