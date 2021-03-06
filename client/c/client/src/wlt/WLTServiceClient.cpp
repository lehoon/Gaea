/*
 *  Copyright Beijing 58 Information Technology Co.,Ltd.
 *
 *  Licensed to the Apache Software Foundation (ASF) under one
 *  or more contributor license agreements.  See the NOTICE file
 *  distributed with this work for additional information
 *  regarding copyright ownership.  The ASF licenses this file
 *  to you under the Apache License, Version 2.0 (the
 *  "License"); you may not use this file except in compliance
 *  with the License.  You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing,
 *  software distributed under the License is distributed on an
 *  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 *  KIND, either express or implied.  See the License for the
 *  specific language governing permissions and limitations
 *  under the License.
 */
/**	
 *  @file     WLTServiceClient.cpp
 *  @brief    
 *  @version  0.0.1
 *  @author   Service Platform Architecture Team (spat@58.com)
 *  @date     2012-02-21 Created it
 *  @note     
 */
 
#include "../serialize/serializer.h"
#include "../serialize/derializer.h"
#include "../client/Parameter.h"
#include "../serialize/strHelper.h"
#include "../struct/struct.h"
#include "WLTServiceClient.h" 


WLTServiceClient *WLTServiceClient::singleton = new WLTServiceClient();

WLTServiceClient::WLTServiceClient()
{
    ps = new gaea::ProxyStandard("wltc", (char*) "WLTExplandServiceBean");
}

WLTServiceClient::~WLTServiceClient() {
	delete ps;
}

bool WLTServiceClient::isVipUser(long long uid)
{
    gaea::Parameter p1(SERIALIZE_LONG_LONG_N, (char*) "Long", (void*) &uid);
    gaea::Parameter *pr[1];
    pr[0] = &p1;
    void *obj = ps->invoke((char*) "getExplandList", pr, 1);
    if(obj == NULL)
    {
        return false;
    }
    else
    {
        serialize_list* listWLTExpland = (serialize_list*)obj;
        if (list_length(listWLTExpland) != 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
