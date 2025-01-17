# Move Data


## Group (Subgroup) ##

Core (Memory/Management)

## Description ##

This **Filter** allows the user to move an **Attribute Array** from one **Attribute Matrix** to another compatible **Attribute Matrix** or to move an **Attribute Matrix** from one **Data Container** to another **Data Container**. **Attribute Matrices** are compatible if the _number of tuples_ are equal, **not** the actual _tuple dimensions_. 

## Parameters ##

| Name | Type | Description |
|------|------| ----------- |
| Data to Move | DataPath | The complete path to the data object to be moved |
| New Parent | DataPath | The complete path to the parent data object to which the data will be moved |

## Required Geometry ##

Not Applicable

## Required Objects ##

| Kind | Default Name | Type | Component Dimensions | Description |
|------|--------------|------|----------------------|-------------|
| **Data Object** | None | Any | N/A | **Data Object** to move |
| **Base Group** Child | None | Any | Any | **Base Group** to be moved into |

## Created Objects ##

None

## Example Pipelines ##



## License & Copyright ##

Please see the description file distributed with this **Plugin**

## DREAM.3D Mailing Lists ##

If you need more help with a **Filter**, please consider asking your question on the [DREAM.3D Users Google group!](https://groups.google.com/forum/?hl=en#!forum/dream3d-users)

