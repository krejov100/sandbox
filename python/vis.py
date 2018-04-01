#!/usr/bin/env python
# -*- coding: utf-8 -*-
# vispy: gallery 1

from vispy import gloo
from vispy.gloo import gl
from vispy import app
from vispy.util.transforms import perspective, translate, scale
from vispy.geometry import create_cube

cube_vert = """
uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;
uniform vec4 u_color;
attribute vec3 position;
attribute vec2 texcoord;
attribute vec3 normal;
attribute vec4 color;
varying vec4 v_color;
void main()
{
    v_color = u_color * color;
    gl_Position = u_projection * u_view * u_model * vec4(position,1.0);
}
"""

cube_frag = """
varying vec4 v_color;
void main()
{
    gl_FragColor = v_color;
}
"""


# ------------------------------------------------------------ Canvas class ---
class Canvas(app.Canvas):
	def __init__(self):
		app.Canvas.__init__(self, keys='interactive', size=(800, 600))
		self.model = scale((1, -1, -1)) @ translate((0, 0, 0))
		self.view = translate((0, 0, 0))
		self.projection = perspective(55, self.size[0] / float(self.size[1]), 0.001, 100)
		v, i, self.outline = create_cube()
		self.frustrum_shader = gloo.Program(cube_vert, cube_frag)
		self.frustrum_shader.bind(gloo.VertexBuffer(v))
		self.cube_model = scale((2, 2, 2)) @ scale((0.05, 0.05, 0.05)) @ translate((0, 0, -0.5))
		gloo.set_state('translucent', clear_color='white')
		gl.glEnable(gl.GL_DEPTH_TEST)
		self.timer = app.Timer('auto', connect=self.on_timer, start=True)
		self.show()

	def on_key_press(self, event):
		pass

	def set_object_transform(self, T):
		self.cube_model = T

	def on_timer(self, event):
		self.update()

	def on_resize(self, event):
		gloo.set_viewport(0, 0, self.physical_size[0], self.physical_size[1])
		self.projection = perspective(55.0, self.size[0] /
		                              float(self.size[1]), 0.01, 1000.0)
		self.frustrum_shader['u_projection'] = self.projection

	def on_draw(self, event):
		gloo.clear()
		gloo.set_state(blend=True, depth_mask=True, polygon_offset_fill=False)
		self.frustrum_shader['u_projection'] = self.projection
		self.frustrum_shader['u_color'] = (1, 1, 1, 1)
		self.frustrum_shader['u_model'] = self.cube_model
		self.frustrum_shader['u_view'] = self.view
		self.frustrum_shader.draw('lines', gloo.IndexBuffer(self.outline))


if __name__ == '__main__':
	c = Canvas()
	app.run()