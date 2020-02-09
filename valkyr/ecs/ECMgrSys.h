#pragma once

#include "../core/vcommon.h"
#include "../core/vplatform.h"
#include <vector>
#include <map>

namespace valkyr{

    const vsize CHUNK_SIZE = 16*1024;

    //chunk list can not be std::vector, 'cause its address can be changed
    //cpts can not be deleted, just not activated in a game scene
    //after a cpt built, its memory will never give back until the whole chunk is clear 

    struct ChunkInfo {
        alignas(8) vint chunkIdx = 0;
        alignas(8) vint numCpt = 0;
        alignas(8) vsize usedSize = 0;
        alignas(8) vsize remainingSize = CHUNK_SIZE;
        alignas(1) bool isFull = false;
        alignas(1) char pad[256 - 33] = { 0 };

        ChunkInfo() {

        }

        ~ChunkInfo() {

        }
    };

    struct Chunk
    {
        ChunkInfo* info;
        char* buff;

        Chunk(){
            buff = new char[CHUNK_SIZE];
            info = new(buff) ChunkInfo();
        }

        ~Chunk(){
            info->~ChunkInfo();
            delete info;
            delete buff;
        }
    };

    struct CptInfo {
        Chunk* chunk = nullptr;
        vint chunkIdx;
        vint offset;
        vsize size;
    };

    class ECMgrSys {

    public:
        ECMgrSys() {
            Chunk* firstChunk = new Chunk();
            chunkList.push_back(firstChunk);
            currChunk = firstChunk;
            currChunkIdx = 0;
        }

        ~ECMgrSys() {
            chunkList.clear();
        }

        template <typename Cpt>
        Cpt* BuildCpt() {
            if (currChunk->info->isFull||sizeof(Cpt) > currChunk->info->remainingSize) {
                currChunkIdx++;
                currChunk->info->isFull = true;
                chunkList.push_back(new Chunk());
                currChunk = chunkList[currChunkIdx];
            }
            currChunk->info->numCpt++;
            currChunk->info->usedSize += sizeof(Cpt);
            currChunk->info->remainingSize = CHUNK_SIZE - currChunk->info->usedSize;
            return new(currChunk->buff) Cpt();
        }

        template <typename HeadCpt, typename NexHead, typename... Cpts>
        void BuildCpt() {
            BuildCpt<HeadCpt>();
            BuildCpt<NexHead, Cpts>();
        }

        template <typename Cpt>
        Cpt* FindCpts() {
            
        }

    private:
        template <typename Cpt>
        Cpt* GetCpt(CptInfo cptInfo) {

        }


        vint currChunkIdx = 0;
        Chunk* currChunk = nullptr;
        std::vector<Chunk*> chunkList;
        std::vector<CptInfo> cptInfoList;
        std::multimap<vint, vint> chunkCptsMap;
        std::multimap<vint, vint> entityCptsMap;
        std::multimap<vint, vint> entityChunksMap;
    };

}
