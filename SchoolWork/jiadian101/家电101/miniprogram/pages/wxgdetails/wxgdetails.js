// miniprogram/pages/wxgdetails/wxgdetails.js
const db = wx.cloud.database({});
var app = getApp();

Page({

  /**
   * 页面的初始数据
   */
  data: {
    name:'',
    showView:true,
    shangchuan:false,
    xiugai:false,
    ping:true,
    tel:'',
    id:'',
  },

  zhifu:function(e){
    db.collection('order').doc(this.data.id).update({
      data:{
        ddzt: '等待客户支付'
      }
    }).then(res =>{
      wx.showToast({
        title:'提交成功',
        icon:'success',
      });
      setTimeout(function () {
        wx.navigateBack({
          delta: 1
        })
      }, 2000);
    }).catch(err=>{
      wx.showToast({
        title:'提交失败',
        icon:'none'
      }) 
    })
  },

  shangchuan:function(e){
    var that = this;
    wx.chooseImage({
      success: chooseResult => {
        wx.cloud.uploadFile({
          cloudPath: "img/" + new Date().getTime() +"-"+ Math.floor(Math.random() * 1000), 
          filePath: chooseResult.tempFilePaths[0],
        }).then(res => {
          db.collection('order').doc(that.data.id).update({
            data:{
              repimg: res.fileID
            }
          }).then(result=>{
            wx.showToast({
              title:'上传成功',
              icon:'success',
            });
            setTimeout(function () {
              wx.navigateBack({
                delta: 1
              })
            }, 2000);
          }).catch(err=>{
            wx.showToast({
              title:'上传失败',
              icon:'none'
            }) 
          })
        }).catch(err => {
          wx.showToast({
            title:'上传失败',
            icon:'none'
          })
        });
      },
    })
  },

  xiugaijine:function(e){
    var id = this.data.id;
    wx.navigateTo({
      url: '../xiugaijine/xiugaijine?id='+id,
    })
  },

  jiedan:function(e){
    db.collection('wxg').where({
      username:this.data.name,
    }).get().then(res => {
      db.collection('order').doc(this.data.id).update({
        data:{
          ddzt: '维修工已接单',
          repname: this.data.name,
          reptel: res.data[0].tel,
        }
      }).then(res => {
        wx.showToast({
          title : '接单成功',
          icon: 'success',
        })
        setTimeout(function () {
          wx.navigateBack({
            delta: 1
          })
        }, 2000);
      }).catch(err => {
        wx.showToast({
          title: '接单失败请重试',
          icon: 'none',
        })
        setTimeout(function () {
          wx.navigateBack({
            delta: 1
          })
        }, 2000);
      })

    }).catch(err => {
      wx.showToast({
        title : '请重试',
        icon:'none',
      })
    });
    
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    db.collection('order').doc(options.id).get({
      success: res => {
        // res.data 包含该记录的数据
        this.setData({
          order: res.data,
          id:options.id
        })
        if(res.data.ddzt=='等待维修工接单'){
          this.setData({
            showView: false
          })
        };
        if(res.data.repimg != ''){
          this.setData({
            shangchuan: true
          })
        };
        if(res.data.ddzt != '维修工已接单'){
          this.setData({
            xiugai: true
          })
        };
        if(res.data.ddzt == '订单已完成'){
          this.setData({
            ping: false
          })
        };
      }
    });
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
      name: app.globalData.globalName
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