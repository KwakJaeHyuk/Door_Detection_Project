# Door_Detection_Project
dyros_project
----

Project Progress<br><br>
--
1. YOLOv3를 사용하여 문고리를 찾아내어 bounding box를 친다.<br>
2. bounding box의 center 픽셀의 찾아내어 그 픽셀에 해당하는 PointCloud 검출<br>
3. ArUco Marker를 사용하여 문고리의 pose를 찾는다.<br>
4. 문고리의 pose를 2번 과정에서 찾은 PointCloud 위치에 대입<br>

Detail<br><br>
--
YOLOv3<br>
    iteration : 3000<br>
- value threshold : 0.3

Result<br>
-> https://user-images.githubusercontent.com/87814705/196609767-4e42f47c-acaf-447e-a81b-9770c232a3fd.mp4



