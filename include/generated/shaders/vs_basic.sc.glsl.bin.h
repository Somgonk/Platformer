static const uint8_t vs_basic_glsl[700] =
{
	0x56, 0x53, 0x48, 0x0b, 0x00, 0x00, 0x00, 0x00, 0xa4, 0x8b, 0xef, 0x49, 0x01, 0x00, 0x0a, 0x75, // VSH........I...u
	0x5f, 0x76, 0x69, 0x65, 0x77, 0x52, 0x65, 0x63, 0x74, 0x02, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, // _viewRect.......
	0x00, 0x00, 0x00, 0x94, 0x02, 0x00, 0x00, 0x61, 0x74, 0x74, 0x72, 0x69, 0x62, 0x75, 0x74, 0x65, // .......attribute
	0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x61, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x3b, 0x0a, //  vec4 a_color0;.
	0x61, 0x74, 0x74, 0x72, 0x69, 0x62, 0x75, 0x74, 0x65, 0x20, 0x76, 0x65, 0x63, 0x32, 0x20, 0x61, // attribute vec2 a
	0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x76, 0x61, 0x72, 0x79, 0x69, // _position;.varyi
	0x6e, 0x67, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, // ng vec4 v_color0
	0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x75, // ;.uniform vec4 u
	0x5f, 0x76, 0x69, 0x65, 0x77, 0x52, 0x65, 0x63, 0x74, 0x3b, 0x0a, 0x76, 0x6f, 0x69, 0x64, 0x20, // _viewRect;.void 
	0x6d, 0x61, 0x69, 0x6e, 0x20, 0x28, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, // main ().{.  floa
	0x74, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, // t tmpvar_1;.  tm
	0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x20, 0x3d, 0x20, 0x28, 0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, // pvar_1 = (u_view
	0x52, 0x65, 0x63, 0x74, 0x2e, 0x77, 0x20, 0x2f, 0x20, 0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, 0x52, // Rect.w / u_viewR
	0x65, 0x63, 0x74, 0x2e, 0x7a, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20, // ect.z);.  float 
	0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, // tmpvar_2;.  tmpv
	0x61, 0x72, 0x5f, 0x32, 0x20, 0x3d, 0x20, 0x28, 0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, 0x52, 0x65, // ar_2 = (u_viewRe
	0x63, 0x74, 0x2e, 0x7a, 0x20, 0x2f, 0x20, 0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, 0x52, 0x65, 0x63, // ct.z / u_viewRec
	0x74, 0x2e, 0x77, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20, 0x74, 0x6d, // t.w);.  float tm
	0x70, 0x76, 0x61, 0x72, 0x5f, 0x33, 0x3b, 0x0a, 0x20, 0x20, 0x69, 0x66, 0x20, 0x28, 0x28, 0x75, // pvar_3;.  if ((u
	0x5f, 0x76, 0x69, 0x65, 0x77, 0x52, 0x65, 0x63, 0x74, 0x2e, 0x77, 0x20, 0x3e, 0x20, 0x75, 0x5f, // _viewRect.w > u_
	0x76, 0x69, 0x65, 0x77, 0x52, 0x65, 0x63, 0x74, 0x2e, 0x7a, 0x29, 0x29, 0x20, 0x7b, 0x0a, 0x20, // viewRect.z)) {. 
	0x20, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x33, 0x20, 0x3d, 0x20, 0x31, 0x2e, //    tmpvar_3 = 1.
	0x30, 0x3b, 0x0a, 0x20, 0x20, 0x7d, 0x20, 0x65, 0x6c, 0x73, 0x65, 0x20, 0x7b, 0x0a, 0x20, 0x20, // 0;.  } else {.  
	0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x33, 0x20, 0x3d, 0x20, 0x74, 0x6d, 0x70, //   tmpvar_3 = tmp
	0x76, 0x61, 0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x20, 0x20, 0x7d, 0x3b, 0x0a, 0x20, 0x20, 0x66, 0x6c, // var_1;.  };.  fl
	0x6f, 0x61, 0x74, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x34, 0x3b, 0x0a, 0x20, 0x20, // oat tmpvar_4;.  
	0x69, 0x66, 0x20, 0x28, 0x28, 0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, 0x52, 0x65, 0x63, 0x74, 0x2e, // if ((u_viewRect.
	0x77, 0x20, 0x3c, 0x20, 0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, 0x52, 0x65, 0x63, 0x74, 0x2e, 0x7a, // w < u_viewRect.z
	0x29, 0x29, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, // )) {.    tmpvar_
	0x34, 0x20, 0x3d, 0x20, 0x31, 0x2e, 0x30, 0x3b, 0x0a, 0x20, 0x20, 0x7d, 0x20, 0x65, 0x6c, 0x73, // 4 = 1.0;.  } els
	0x65, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x34, // e {.    tmpvar_4
	0x20, 0x3d, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x3b, 0x0a, 0x20, 0x20, 0x7d, //  = tmpvar_2;.  }
	0x3b, 0x0a, 0x20, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, // ;.  vec4 tmpvar_
	0x35, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x35, 0x2e, 0x7a, 0x77, // 5;.  tmpvar_5.zw
	0x20, 0x3d, 0x20, 0x76, 0x65, 0x63, 0x32, 0x28, 0x30, 0x2e, 0x30, 0x2c, 0x20, 0x31, 0x2e, 0x30, //  = vec2(0.0, 1.0
	0x29, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x35, 0x2e, 0x78, 0x20, // );.  tmpvar_5.x 
	0x3d, 0x20, 0x28, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x2e, 0x78, 0x20, // = (a_position.x 
	0x2a, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x33, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x74, // * tmpvar_3);.  t
	0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x35, 0x2e, 0x79, 0x20, 0x3d, 0x20, 0x28, 0x61, 0x5f, 0x70, // mpvar_5.y = (a_p
	0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x2e, 0x79, 0x20, 0x2a, 0x20, 0x74, 0x6d, 0x70, 0x76, // osition.y * tmpv
	0x61, 0x72, 0x5f, 0x34, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x67, 0x6c, 0x5f, 0x50, 0x6f, 0x73, 0x69, // ar_4);.  gl_Posi
	0x74, 0x69, 0x6f, 0x6e, 0x20, 0x3d, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x35, 0x3b, // tion = tmpvar_5;
	0x0a, 0x20, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x20, 0x3d, 0x20, 0x61, 0x5f, // .  v_color0 = a_
	0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x00,                         // color0;.}...
};
