uniform sampler2D u_Texture0;
uniform sampler2D u_Texture1;
uniform sampler2D u_Texture2;
uniform sampler2D u_Texture3;
uniform float u_Time;
uniform vec2 u_Resolution;

uniform vec4 u_PalPos;
uniform vec2 u_PalCoords;

varying vec2 v_TexCoords;
varying vec2 v_Position;




$



$

void main()	{

	vec2 a_TexCoords = uv.xy;
	v_TexCoords.x = (uv.x*32.0 + (u_PalPos.x-16.0)) / 1024.0;
	v_TexCoords.y = (96.0-(uv.y*32.0 + (u_PalPos.y-16.0))) / 96.0;
	//v_TexCoords.y = 1.0-v_TexCoords.y;
	gl_Position = vec4( position.xyz, 1.0 );

}

$

void main()	{
	gl_FragColor = texture2D( u_Texture0, v_TexCoords );
	
}
