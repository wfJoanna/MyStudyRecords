// pages/index2/index2.js
const db = wx.cloud.database(); //初始化云数据库
var app = getApp();

Page({

  /**
   * 页面的初始数据
   */
  data: {
    orderid: "",
    time: "",
    username: '',
    name: "",
    tel: "",
    jdtype: "",
    description: "",
    region: ['xx省', 'xx市', 'xx区'],
    address: "",
  },


  regionChange: function (e) {
    this.setData({
      region: e.detail.value
    })
  },

  getForm: function (e) {
    var date = new Date();
    var id = this.data.username + date.getFullYear().toString() + (date.getMonth() + 1).toString() + date.getDate().toString() + date.getHours().toString() + date.getMinutes().toString() + date.getSeconds().toString();
    this.setData({
      orderid: id
    });
    this.setData({
      time: date.getFullYear().toString()+'年'+(date.getMonth()+1).toString()+'月'+date.getDate().toString()+'日'
    })
    var formdata = e.detail.value;
    this.setData({
      name: formdata.name,
      tel: formdata.tel,
      jdtype: formdata.jdtype,
      description: formdata.description,
      region: formdata.region,
      address: formdata.address
    })
    db.collection("order").add({
      data: {
        orderid: this.data.orderid,
        status: '未完成',
        ddzt: '等待维修工接单',
        time: this.data.time,
        username: this.data.username,
        name: this.data.name,
        tel: this.data.tel,
        jdtype: this.data.jdtype,
        description: this.data.description,
        region: this.data.region.toString(),
        address: this.data.address,
        money: '30元',
        repname: '',
        reptel: '',
        repimg: '',
        evrepair: 5
      }
    }).then(res => {
      wx.showToast({
        title: '上传成功'
      })
      setTimeout(function () {
        wx.reLaunch({
          url: '/pages/index1/index1'
        })
      }, 2000);
    }).catch(res => {
      wx.showToast({
        title: '上传失败'
      })
    })
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {

  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {
    this.setData({
      username: app.globalData.globalName
    })
  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})