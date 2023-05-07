#ifndef KHTTPD_HTTP_SERVER_H
#define KHTTPD_HTTP_SERVER_H

#include <linux/module.h>
#include <linux/workqueue.h>
#include <net/sock.h>
#include "http_parser.h"
#define MODULE_NAME "khttp"

struct http_server_param {
    struct socket *listen_socket;
};

struct khttp_service {
    bool is_stopped;
    struct list_head head;
};

struct http_request {
    struct socket *socket;
    enum http_method method;
    char request_url[128];
    int complete;
    struct list_head node;
    struct work_struct khttp_work;
};

extern struct khttp_service daemon;

extern int http_server_daemon(void *arg);

#endif
