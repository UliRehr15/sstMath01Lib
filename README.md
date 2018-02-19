# sstMath01Lib
sst geometric functions and classes

Licence:  GNU LESSER GENERAL PUBLIC LICENSE, Version 3.0

Coordinate Transformations classes (Trn) between
  - World Coordinates (UTM, Gauss Krueger ... )
  - Model Coordinates (Database Coordinates)
  - Device (Screen) Coordinates

Class for Minimum Bounding Rectangles (Mbr)

Compile with QT 5.5.1 and QTCreator 3.5.1

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
