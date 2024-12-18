=====Input Error Cases=====
dup_a.rt
- Description: Duplicate ambient light (A) identifiers defined in the scene file.
- Expected Output: Error\n error msg

dup_c.rt
- Description: Duplicate camera (C) identifiers defined in the scene file.
- Expected Output: Error\n error msg

dup_l.rt
- Description: Duplicate light (L) identifiers defined in the scene file.
- Expected Output: Error\n error msg

invalid_a_elnum.rt
- Description: Ambient light (A) does not have the correct number of elements.
- Expected Output: Error\n error msg

invalid_a_numrange.rt
- Description: Ambient light (A) ratio or color values are out of range.
- Expected Output: Error\n error msg

invalid_c_elnum.rt
- Description: Camera (C) does not have the correct number of elements.
E- xpected Output: Error\n error msg

invalid_c_numrange.rt
- Description: Camera (C) orientation vector values or FOV are out of range.
- Expected Output: Error\n error msg

invalid_cy_elnum.rt
- Description: Cylinder (cy) does not have the correct number of elements.
- Expected Output: Error\n error msg

invalid_l_elnum.rt
- Description: Light (L) does not have the correct number of elements.
- Expected Output: Error\n error msg

invalid_l_numrange.rt
- Description: Light (L) brightness ratio or color values are out of range.
- Expected Output: Error\n error msg

invalid_pl_elnum.rt
- Description: Plane (pl) does not have the correct number of elements.
- Expected Output: Error\n error msg

invalid_pl_numrange.rt
- Description: Plane (pl) vector is not normalized or color values are out of range.
- Expected Output: Error\n error msg

invalid_sp_elnum.rt
- Description: Sphere (sp) does not have the correct number of elements.
- Expected Output: Error\n error msg

invalid_sp_numrange.rt
- Description: Sphere (sp) color values are out of range.
- Expected Output: Error\n error msg

invalidfilenamert
- Description: The scene file does not end with the .rt extension.
- Expected Output: Error\ error msg

invlalid_c_nnv.rt
- Description: Camera (C) orientation vector is not normalized.
- Expected Output: Error\n error msg

=====Scenes=====
camera_xaxis.rt
- Description: Camera positioned along the x-axis facing the center of the scene.
- Expected Output: The scene is displayed correctly with no glitches.

camera_zaxis.rt
- Description: Camera positioned along the z-axis facing the center of the scene.
- Expected Output: The scene is displayed correctly with no glitches.

cy_yaxis.rt
- Description: Cylinder extending along the y-axis, viewed from the camera.
- Expected Output: The cylinder is visible and displayed correctly without glitches.

id_objects.rt
- Description: Scene with a sphere, plane, and cylinder.
- Expected Output: All objects are visible and displayed correctly.

intersect_obj.rt
- Description: Intersecting objects (e.g., a sphere and cylinder) in the scene.
- Expected Output: Both objects are rendered without glitches, including intersections.

mult_obj_shadow.rt
- Description: Multiple objects casting shadows in the scene.
- Expected Output: Shadows are rendered correctly without glitches.

no_id.rt
- Description: The file does not include a valid identifier as the first element.
- Expected Output: Error\nInvalid identifier

planez0.rt
- Description: Plane at z = 0, viewed from the camera.
- Expected Output: The plane is visible and displayed correctly.

rotate_cy.rt
- Description: A cylinder is rotated along one of the axes.
- Expected Output: The cylinder is rendered in the rotated position without glitches.

slidelit_sp.rt
- Description: Sphere illuminated from the side by a light source.
- Expected Output: The sphere is illuminated on one side with correct light rendering.

sp_shadow.rt
- Description: A sphere casting a shadow on a plane.
- Expected Output: The sphere's shadow is rendered on the plane without glitches.

sphere000.rt
- Description: Sphere placed at coordinates {0, 0, 0}.
- Expected Output: The sphere is visible at the center of the scene.

trans_slidelit_sp.rt
- Description: Translated sphere illuminated from the side by a light source.
- Expected Output: The sphere is rendered in its translated position with correct lighting.

two_trans_sp.rt
- Description: Two spheres, one translated to a different position.
- Expected Output: Both spheres are visible without glitches.