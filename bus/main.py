import apps.db as db
import apps.misp as misp
import asyncio
from backbone import InMemoryBackbone
from bus import VASTBus


async def main():
    backbone = InMemoryBackbone()
    vast = VASTBus(backbone)

    # run all the apps in parallel
    db_task = asyncio.create_task(db.start(vast))
    misp_task = asyncio.create_task(misp.start(vast))
    await db_task
    await misp_task


if __name__ == "__main__":
    asyncio.run(main())
