# sstMath01Lib
sst geometric functions and classes

Licence:  GNU LESSER GENERAL PUBLIC LICENSE, Version 3.0

Coordinate Transformations classes (Trn) between
  - World Coordinates (UTM, Gauss Krueger ... )
  - Model Coordinates (Database Coordinates)
  - Device (Screen) Coordinates

Class for Minimum Bounding Rectangles (Mbr)
Class for Calculating with Angle Values

This Library is created with QtCreator 4.11.0 and gcc 9.3.0.

Structure of coding projects should be:

.. [libs]
   [Doxygen_output] <BR>
   [sst_str01_lib] <BR>


20170107: Version 1.0: First Check In. <BR>
20170411: Version 1.1: Minimum Boundary Rectangle (Mbr) class with some functions. <BR>
20170418: Version 1.2: Rework interface of Mbr Class.  <BR>
20170628: Version 1.3: Mbr Values now private, more Getter functions. <BR>
20170723: Version 1.4: Small corrections. <BR>
20170803: Version 1.5: Member of Mbr now private. <BR>
20180215: Version 1.6: Class Mbr: New function Mbr to csv string. <BR>
                       Lib sstMath01Lib needs now Lib sst_str01_lib. <BR>
20180219: Version 1.7: Class CoorTrn: New functions Transform_WC_DC, Transform_DC_WC. <BR>
20180309: Version 1.8: A lot of functions of D2Pnt and D3Pnt, most still in german. <BR>
20180914: Version 1.9: Update to QtCreator 4.5.2 and gcc 7.3.0. <BR>
20181010: Version 1.10: New Convert 3D Pnt to csv string function. <BR>
20181102: Version 1.11: Getter functions for 2d double Pnt, 3d double Pnt Classes. <BR>
20181124: Version 1.12: New Scal Distance functions for CoorTrn Class.  <BR>
20190524: Version 1.13: Add Helper Class for Calculating with Angle Values. <BR>
20190603: Version 1.14: Fixed problems in use of scal, move and rotate of transformation. <BR>
20190617: Version 1.15: More functions for coordinate transformation of points. <BR>
20200127: Version 1.16: Better Names for Defines, more functions for coordinate transformation. <BR>
20201020: Version 1.17: Add Mode for Transform Screen Coordinates: Transform to Screen Center. <BR>
                        It is used by Qt QPainterPath Displaying System. <BR>
20201020: Version 1.18: Small corrections in Doxygen Dokumentation. <BR>
20210122: Version 1.19: New d2 Double Point class function -CircleCalcCenterWithTwoPntsAndRad-. <BR>
20210205: Version 1.20: Small corrections with CircleCalcCenterWithTwoPntsAndRad. <BR>
20210307: Version 1.21: Small corrections in Calculate Angle Differences. <BR>
