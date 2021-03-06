//
// Created by wuwei on 17-3-26.
//
#pragma once
#ifndef UAVPRODUCT_UAVGEOPROC_H
#define UAVPRODUCT_UAVGEOPROC_H

#include<string>
using namespace std;

class UAVGeoProc {
public:
    /***
     * 根据光束法平差结果直接进行几何校正
     */
    bool UAVGeoProc_GeoProc(double dGroundSize, double dL, double dB);

    /*
     * 根据光束法平差结果直接进行几何校正,校正到web 摩卡托坐标系
     * */
    bool UAVGeoProc_GeoProcWMT(double dGroundSize,double dL,double dB);

    /***
     * 根据影像控制点进行几何校正
     * @param pathSFM ：SFM数据路径
     * @param pathDstDir ：几何校正结果输出路径
     * @param dL ：中心经度
     * @param dB ：中心纬度
     */

    bool UAVGeoProc_GeoProc(string pathSFM,string pathDstDir,double dGroundSize,double dL,double dB);
    bool UAVGeoProc_GeoProcWMT(string pathSFM,string pathDstDir,double dGroundSize,double dL,double dB);

    /***
    * 根据影像控制点进行几何校正
    * @param pathSFM ：SFM数据路径
     * string pathDem:DEM数据路径
    * @param pathDstDir ：几何校正结果输出路径
    * @param dL ：中心经度
    * @param dB ：中心纬度
    */
    bool UAVGetProc_GeoProcDEM(string pathSFM, string pathDem,string pathDstDir, double dGroundSize, double dL, double dB);
    /***
     * 将地心直角坐标系转换为UTM坐标系
     * @param gcps ：控制点（输入-输出）
     * @param num ：控制点个数
     * @param dL ：中心经度
     * @param dB ：中心纬度
     */
    void UAVGetProc_GeoCoordiTrans(double *gcps, int num, double dL, double dB);

    /***
     * 通过控制点进行几何校正
     * @param image ：影像路径
     * @param gcps ：控制点
     * @param gcpNum ：控制点数
     * @param dGroundSize ：地面分辨率
     * @param dL ：中心经度
     * @param dB ：中心纬度
     * @param geoImage ：校正后的影像
     */

    void UAVGeoProc_GeoCorrection(string image, double *gcps, int gcpNum, double dGroundSize, double dL, double dB,
                                  string geoImage);

    /***
     *首先通过控制点解算出外方位元素，在获取外方位元素的基础上使用DEM数据进行几何精校正
     *string image：输入影像
     *double* gcps：控制点文件
     *int gcpNum：控制点个数
     *double dGroundSize地面分辨率
     *double dL,double dB 经纬度
     *string imageDem DEM影像数据
     *string geoImageAccur 几何精校正数据
    */
    void
    UAVGeoProc_GeoCorrectionWithDEM(string image, double *gcps, int gcpNum, double dGroundSize, double Xs, double Ys,
                                    double Zs, double fLen, string imageDem, string geoImageAccur);

private:
    /***
     * unsigned char* pDataSrc:输入影像数据
     * xMap：ｘ映射
     * yMap：ｙ映射
     * double dGroundSize：地面点分辨率
     * int xsrc，int ysrc：源影像大小
     * int xre,int yre　：采样后影像大小
     * unsigned char* pDataRe：采样后数据
     */
    void UAVGeoProc_ImageResample(unsigned char *pDataSrc, float *xMap, float *yMap, double maxpt[], double minpt[],
                                  double dGroundSize, int xsrc, int ysrc, int xre, int yre, unsigned char *pDataRe);
};
#endif //UAVPRODUCT_UAVGEOPROC_H
