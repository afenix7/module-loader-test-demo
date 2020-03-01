#pragma once
//#include "../d3d11Renderer/plugin_d3d11Renderer.h"
//loop
#include "../${mod}/plugin_${mod}.h"
//end

namespace valkyr{
    void modulesStart(){
        //d3d11RendererStart();
//loop
        ${mod}Start();
//end
    }

    void modulesStop(){
        //d3d11RendererStop();
//loop
        ${mod}Stop();
//end
    }


}


