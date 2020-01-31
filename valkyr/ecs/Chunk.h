#pragma once

#include "../core/vcommon.h"
#include "../core/vplatform.h"

namespace valkyr::ecs{

    const vsize CHUNK_SIZE = 16*1024;

    //chunk list can not be std::vector, 'cause its address can be changed
    //cpts can not be deleted, just not activated in a game scene
    //after a cpt built, its memory will never give back until the whole chunk is clear 

    struct Chunk
    {
    
    public:
        Chunk(){
            buff = new char[CHUNK_SIZE];

        }

        template <typename Cpt>
        Cpt* Build(){
            usedSize += sizeof(Cpt);
            return new(buff) Cpt();
        }

        template <typename HeadCpt,typename NexHead,typename... Cpts> 
        void Build(){
            Build<HeadCpt>();
            Build<NexHead,Cpts>();
        }

        template <typename Cpt>
        Cpt* GetCpt(int ){

        }

        ~Chunk(){
            delete buff;
        }
    
    private:
        char* buff;
        vint* numCpt;
        vsize* usedSize;
    };

}
