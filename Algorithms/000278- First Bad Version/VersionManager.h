class VersionManager
{
public:
    int n, bad;

public:
    bool isBadVersion(int version)
    {
        return version >= bad;
    }

    void setBad(int n, int bad)
    {
        this->n = n;
        this->bad = bad;
    }
};

VersionManager versionmanager;
bool isBadVersion(int version)
{
    return versionmanager.isBadVersion(version);
}

void setBad(int n, int bad)
{
    return versionmanager.setBad(n, bad);
}