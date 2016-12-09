#ifndef DATAMANAGER_H
#define DATAMANAGER_H


class DataManager
{
public:
    DataManager();
    int getSaveSlot();
    void setSaveSlot(int index);
    int quickSave(int slot);
private:
    int slotNumber;
};

#endif // DATAMANAGER_H
