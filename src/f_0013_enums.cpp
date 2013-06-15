
const float AIR_VAL = 0.0f;
const float WATER_VAL = 1.0f;
const float SOLID_THRESH = 2.0f;
const float GRASS_VAL = 2.0f;
const float ROCK_VAL = 3.0f;
const float DIRT_VAL = 4.0f;


enum eProgramState {
	E_PS_MENU,
	E_PS_IN_GAME,
	E_PS_SIZE
};

enum eProgramAction {
	E_PA_QUIT,
	E_PA_TOGGLE_FULLSCREEN,
	E_PA_REFRESH,
	E_PA_SIZE
};

enum eRenderStates {
	E_RENDER_SOLID,
	E_RENDER_WATER
};

enum eMouseStates {
	E_MOUSE_UP,
	E_MOUSE_DOWN
};

enum TEX_ENUMS {
	E_TEX_NOISE,
	E_TEX_SIMPLEX,
	E_TEX_VORONOI,
	E_TEX_TOTAL
};

enum PAGE_FUNCS {
	OP_NULL,
	S_INIT,
	E_INIT,
	S_OP_CLEAR,
	E_OP_CLEAR,
	S_OP_SIMPLEX_NOISE,
	E_OP_SIMPLEX_NOISE,
	S_OP_SEAMLESS_SIMPLEX_NOISE,
	E_OP_SEAMLESS_SIMPLEX_NOISE,
	S_OP_VORONOI,
	E_OP_VORONOI,
	S_OP_APPLY_TEXTURE,
	E_OP_APPLY_TEXTURE,
	S_RENDER_VOXELS,
	E_RENDER_VOXELS,
	S_CREATE_DL,
	E_CREATE_DL
};

string PAGE_FUNC_STRINGS[] = {
	"OP_NULL",
	"S_INIT",
	"E_INIT",
	"S_OP_SIMPLEX_NOISE",
	"E_OP_SIMPLEX_NOISE",
	"S_OP_SEAMLESS_SIMPLEX_NOISE",
	"E_OP_SEAMLESS_SIMPLEX_NOISE",
	"S_OP_VORONOI",
	"E_OP_VORONOI",
	"S_OP_APPLY_TEXTURE",
	"E_OP_APPLY_TEXTURE",
	"S_OP_CLEAR",
	"E_OP_CLEAR",
	"S_RENDER_VOXELS",
	"E_RENDER_VOXELS",
	"S_CREATE_DL",
	"E_CREATE_DL"
};

enum RULE_SETS {
	RS_TERRAIN
};

enum FILL_STATES {
	FILL_STATE_AIR,
	FILL_STATE_WATER,
	FILL_STATE_SOLID,
	FILL_STATE_MIXED
};

enum eSSProperties {
	
	E_SS_BGCOL0_R,
	E_SS_BGCOL0_G,
	E_SS_BGCOL0_B,
	E_SS_BGCOL0_A,

	E_SS_BGCOL1_R,
	E_SS_BGCOL1_G,
	E_SS_BGCOL1_B,
	E_SS_BGCOL1_A,

	E_SS_FGCOL0_R,
	E_SS_FGCOL0_G,
	E_SS_FGCOL0_B,
	E_SS_FGCOL0_A,

	E_SS_FGCOL1_R,
	E_SS_FGCOL1_G,
	E_SS_FGCOL1_B,
	E_SS_FGCOL1_A,

	E_SS_BGCOLTEXT0_R,
	E_SS_BGCOLTEXT0_G,
	E_SS_BGCOLTEXT0_B,
	E_SS_BGCOLTEXT0_A,

	E_SS_BGCOLTEXT1_R,
	E_SS_BGCOLTEXT1_G,
	E_SS_BGCOLTEXT1_B,
	E_SS_BGCOLTEXT1_A,

	E_SS_FGCOLTEXT0_R,
	E_SS_FGCOLTEXT0_G,
	E_SS_FGCOLTEXT0_B,
	E_SS_FGCOLTEXT0_A,

	E_SS_FGCOLTEXT1_R,
	E_SS_FGCOLTEXT1_G,
	E_SS_FGCOLTEXT1_B,
	E_SS_FGCOLTEXT1_A,

	E_SS_TGCOL0_R,
	E_SS_TGCOL0_G,
	E_SS_TGCOL0_B,
	E_SS_TGCOL0_A,

	E_SS_TGCOL1_R,
	E_SS_TGCOL1_G,
	E_SS_TGCOL1_B,
	E_SS_TGCOL1_A,

	E_SS_BDCOL_R,
	E_SS_BDCOL_G,
	E_SS_BDCOL_B,
	E_SS_BDCOL_A,

	E_SS_PADDING,
	E_SS_BORDER,
	E_SS_MARGIN,
	E_SS_CORNERRAD,
	E_SS_ROUNDNESS,

	E_SS_PROPS_SIZE
};

enum eCompStates {
	E_COMP_UP,
	E_COMP_OVER,
	E_COMP_DOWN,
	E_COMP_TOTAL
};