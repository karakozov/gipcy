
#ifndef __IPCIOTCL_H__
#define __IPCIOTCL_H__

//-----------------------------------------------------------------------------

#define IPC_DRIVER_NAME             "ipc_driver"
#define MAX_IPCDEVICE_SUPPORT       1

//-----------------------------------------------------------------------------

#ifdef __linux__
#include <linux/types.h>
#ifndef __KERNEL__
#include <sys/ioctl.h>
#endif
#define IPC_DEVICE_TYPE             'i'
#define IPC_MAKE_IOCTL(c) _IO(IPC_DEVICE_TYPE, (c))
#endif

#define IOCTL_IPC_OPEN		IPC_MAKE_IOCTL(10)
#define IOCTL_IPC_LOCK		IPC_MAKE_IOCTL(11)
#define IOCTL_IPC_UNLOCK	IPC_MAKE_IOCTL(12)
#define IOCTL_IPC_RESET		IPC_MAKE_IOCTL(13)
#define IOCTL_IPC_CLOSE		IPC_MAKE_IOCTL(14)

//-----------------------------------------------------------------------------

#ifdef __linux__
#ifdef __KERNEL__
    //! Описывает параметры для команд управления устройством
    struct ioctl_param {
        void *srcBuf;       //!< буфер с данными для устройства (через него передаются данные В драйвер нулевого кольца)
        int srcSize;        //!< размер буфера с данными для устройства
        void *dstBuf;       //!< буфер с данными от устройства  (через него передаются данные ИЗ драйвера нулевого кольца)
        int dstSize;        //!< dstSize - размер буфера с данными от устройства
    };
#endif
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

struct ipc_create_t {

    int     type;
    char    name[128];
    int     value;
    void    *handle;
};

//-----------------------------------------------------------------------------

struct ipc_lock_t {

    void    *handle;
    int     timeout;
};

//-----------------------------------------------------------------------------

struct ipc_unlock_t {

    void    *handle;
};

//-----------------------------------------------------------------------------

struct ipc_close_t {

    void    *handle;
};

//-----------------------------------------------------------------------------

#endif //_IPCIOTCL_H_