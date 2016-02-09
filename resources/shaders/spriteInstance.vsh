#version 330

// very simple vertex shader that just transforms an object-space
// position into clip space and passes along a texture coordinate

in vec4 position;
in vec4 normal;
in vec2 uv;

uniform samplerBuffer data_tbo;

uniform mat4 Projection;
uniform mat4 View;
//uniform vec4 colorToAlpha;

out VERTEX
{
	vec2 UV;
	vec4 Color;
	//vec4 ColorToAlpha;
}vertex;

void main()
{
	int texelLocation = gl_InstanceID * 4;
	//get components from texture buffer with get texel
	vec4 posRot			= texelFetch(data_tbo, texelLocation );
	vec4 origin_scale	= texelFetch(data_tbo, texelLocation + 1);
	vec4 uvData			= texelFetch(data_tbo, texelLocation + 2);
	vec4 color			= texelFetch(data_tbo, texelLocation + 3);

	float cosRot = cos(posRot.w);
	float sinRot = sin(posRot.w);

	mat4 m4Model = mat4(vec4( cosRot, -sinRot, 0, 0),
						vec4( sinRot, cosRot, 0, 0),
						vec4(0, 0, 1, 0),
						vec4(posRot.x, posRot.y, posRot.z, 1));
	
	
	vertex.UV = uv * uvData.zw + uvData.xy;
	vertex.Color = color;
	//vertex.ColorToAlpha = colorToAlpha;

	vec4 adjustedPos = ((position - vec4(origin_scale.x, origin_scale.y, 0.0, 0.0)) * vec4(origin_scale.z, origin_scale.w, 0.0, 1.0));
	gl_Position = Projection * View * m4Model * adjustedPos;
}
