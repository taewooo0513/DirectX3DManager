float Size;
float4x4 matW,matPV;

struct VS_INPUT
{
	float3 normal : NORMAL;
	float3 pos : POSITION;
};

struct VS_OUTPUT
{
	float4 pos : POSITION;
	float4 color : COLOR;
};

VS_OUTPUT vs_main(VS_INPUT input)
{
	VS_OUTPUT output = (VS_OUTPUT)0;
	//input.pos = mul(float3(input.pos) + input.normal * 10, matW);
	//output.pos = mul(input.pos, matPV);
	//output.color = float4(0,1,0,1);
	//return output;

	output.pos = mul(float4(input.pos + input.normal * 0.5, 1), matW);

	output.pos = mul(output.pos, matPV);
	output.pos.z += 0.1f;
	output.color = float4(0, 1, 0, 1);

	return output;
}

struct PS_OUTPUT
{
	float4 color :COLOR;
};

PS_OUTPUT ps_main(VS_OUTPUT input)
{
	PS_OUTPUT output;
	output.color = input.color;
	return output;
}
technique Shader
{
	pass p0
	{
		VertexShader = compile vs_2_0 vs_main();
		PixelShader = compile ps_2_0 ps_main();
	}
};