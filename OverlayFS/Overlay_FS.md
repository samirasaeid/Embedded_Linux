# OVERLAY FILE SYSTEM
- What is Overlay File System?
- Steps needed to make OverlayFS. 

- Task :: push the confirmation file in **[/etc]**



### What is Overlay File System?
OverlayFS operates by merging two filesystems – the upper (read-write) layer and the lower (read-only) layer. This unique approach allows us to combine the contents of these layers into a single unified view while keeping their original attributes intact.

The upper layer acts as a transparent overlay where any changes or additions we make are stored, without altering the lower layer’s underlying data.

![Reference Image](/450-Figure+1.png.jpg)

This makes it particularly advantageous for creating customized views of data, enabling us to construct dynamic configurations without affecting the core files.


### Steps needed to make OverlayFS.
- Creating an OverlayFS instance involves specifying the lower and upper directories.

- Installation 

    OverlayFS is part of the Linux kernels 3.18 and higher, therefore it’s readily available in all modern Linux distributions.

    On distributions like Debian and Ubuntu, we can install it using apt-get:
    
    `$ sudo apt-get install overlayroot `

- Usage

    `# mount -t overlay overlay -o lowerdir=/lower,upperdir=/upper,workdir=/work /merged`

    1. The lower directory can be read-only or could be an overlay itself.
    2. The upper directory is normally writable.
    3. The workdir is used to prepare files as they are switched between the layers


### Task :: push the confirmation file in **[/etc]**

- `mkdir /overlay /merged`
    
- `mount -t overlay overlay -o lowerdir=/etc,upperdir=/data,workdir=/overlay /merged`

-------------------------------------------------------------------------------------

# What is the linux behavior in the following situations ?

### 1. **You need to mount a file system onto a directory that already contains some files.**

------->   Just "shadowed" and will be there again when unmounted

- In fact the files are "there" intact and if you need to reach them right away, w/o unmounting, this can be worked-around with so-called bind mount:

    `mount --bind /Original/FS/Mount/Point /Somewhere/Else`

- It works (so) because when you ask kernel to mount a filesystem to some mountpoint, kernel treats that mountpoint as a "view port" to filesystem you're mounting, so it's expected you shall see mounted FS content there.

### 2. **You are tasked with mounting a new file system onto a directory that already contains files and possibly other data.**
    
In Linux, when you mount a new file system onto a directory that already contains files and data, the behavior of the system depends on the specific configuration and options used during the mount process. Here are a few scenarios that can occur:

- **Overlaying the existing directory:** By default, when you mount a new file system on a directory that already contains files and data, the existing contents of the directory become hidden or "overlayed" by the new file system. The files and directories from the new file system become visible and accessible within the mount point directory.

- **Accessing the existing data:** When the existing directory is overlayed by the new file system, the original files and data may not be directly accessible within that mount point. However, the original files are not deleted or modified; they are simply obscured by the new file system.

- **Remounting with the bind option:** Instead of overlaying the existing directory, you can use the "bind" mount option to mount the new file system while still allowing access to the existing data within the same directory. This creates a "union" of the two file systems, where both the original data and the new file system's data are visible within the mount point directory.

- **Conflict resolution:** If there are files or directories with the same names in the existing directory and the new file system, conflicts may arise. In such cases, the behavior depends on the mount options used. By default, the new file system's data takes precedence, and the existing data becomes hidden. However, you can use specific mount options (e.g., --bind) to control the behavior in case of conflicts.

