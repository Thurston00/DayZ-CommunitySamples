# DayZ Community Weapon Samples

This section is for anything weapons related: Firearms, Melee, or Attachments.

## Contribution

To contribute to this repository, please make a pull request with your changes or additions. Any changes or additions that have not been tested will be rejected.

You must ONLY upload source (unbinarized, unobfuscated and uncompressed) files. Anything else will be rejected.

## File Structure

When contributing to this repository, you must follow the structure below:
```
Sample_Weapon
      - Sub-Folder
           - Texture.paa
           - Material.rvmat
      - Sub-Folder2
           - Proxy.p3d
      - Config.cpp
      - Weapon.p3d
```

All samples should be setup to work as a standalone mod. Any config/texture/model paths should be relative from the sample parent folder.

An example model path in a config would be `Sample_Weapon\WeaponModel.p3d`.