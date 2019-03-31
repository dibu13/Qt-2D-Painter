# Qt-2D-Painter
2D vector shapes painter with GameObjects & components hierarchy.
## Contributors
* Rubén Sardón - [@cumus](https://github.com/cumus)
* Daniel Triviño - [@dibu13](https://github.com/dibu13)
## Features
### Main menu bar
Icons menu bar with the most important actions.
* #### New Scene
Open a new scene.
* #### Open Scene
Open a scene you save before.
* #### Save Scene
Save the scene current state.
* #### Open readme
Opens the readme file.
### Hierarchy
Here you can see the existing entities and you can click hover to select it and opens it at inspectors dock.
* #### Add Entity
Adds an entity with the name of the input text to the scene.
* #### Remove Entity
Removes the selected entity
### BackGround Color
You can select the background color.
### Inspector
Shows the information of the selected entity of all its components.
* #### Component GameObject
With the CheckBox you can activate or deactivate the entity. If the entity is deactivate it doesn't apear at the scene.
* #### Component Tranform
Allows to see and edit the position and the scale of the entity
* #### Component Render
  * **Shape**: Selects the shape, circle or rectangle.
  * **Size**: Modifies the size of the shape.
  * **Fill color**: Picks the fill color.
  * **Stroke color**: Select the stroke line color.
  * **Stroke Thickness**: Modifies the thickness of the strokes line.
  * **Stroke Style**: Select the line style. None, Solid, Dash, Dot, Dash dot and Dash dot dot.
### Scene
Draws all the entities.
## QT Features implemented
* Slots
* QApplication & QMainWindow
* QToolBar &  QMenuBar
* QDesktopServices & QUrl
* QMessageBox
* QFile & QDataStream
* QDockWidget (Hierarchy and Inspector)
* QVector
* QQSpacerItem
* QPainter
* QColor & QColorDialog
